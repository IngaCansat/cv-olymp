#include "mainwindow.h"

#define PATH "/Users/inga/Desktop/MSHP/Untitled.mov"
#define FRAME_WIDTH 640
#define FRAME_HEIGHT 480
#define MAX_NUM_OBJECTS 500
#define MAX_OBJECT_AREA FRAME_HEIGHT*FRAME_WIDTH/1.5

using namespace cv;

// хранит значение номера текущего кадра
long N_curr_frame = 0;
bool use_USBcam = false;

// если появился новый обьект с нормальной площадью, то нужно определить,
// является ли он новым, или это просто новая точка уже существующего обьекта.
// так вот, если расстояние от потенциального обьекта до какого-нибудь из существующих
// обьектов > этой переменной, то этот обьект является новым
int MIN_DIST = 50;

int x, y;
double distance = 0.0;

class Robot {
public:
    // номер кадра первого появления
    long first_frame;
    long N_of_last_frame;
    int id;
    cv::String robot_color;
    //double dist_from_line;
    // значения всех точек обьекта
    std::vector <Point> lastPoints;
    // текущие координаты
    Point curr_coordinates;
    // предыдущие координаты
    Point prev_coordinates;
    // текущие координаты на линии
    Point curr_line_coordinates;
    // хранит расстояние от данного обьекта до каждого существующего*/
    // определяет цвет обьекта
    Robot (int N_curr_frame, int index, cv::String color) {
        // при инициализации нового обьекта кадр его первого появления есть текущий кадр
        first_frame = N_curr_frame;
        id = index;
        robot_color = color;
        // координаты пока такие
        curr_coordinates = Point(x, y);
        prev_coordinates = Point(x, y);
        //lastPoints.emplace_back(Point(x, y));
    }
    ~Robot() {

    }
};
// вектор всех обьектов, которые подходят по площади
// и которые находятся достаточно далеко от уже существующих обьетов
std:: vector <Robot> objects;

// функция вычисления расстояния между точками
double getDistance (Point one, Point two) {
    return ( sqrt( (one.x - two.x)*(one.x - two.x) + (one.y - two.y)*(one.y - two.y) ) );
}
Point findCenter (Point one, Point two) {
    return ( Point(abs((one.x + two.x)/2), abs((one.y + two.y)/2)) );
}

String intToString (int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

int targetR = 0, targetG = 255, targetB = 0;
void drawObject (int x, int y, Mat &frame, Mat cameraFeed, Robot robot) {
    circle(cameraFeed,Point(x,y),20,Scalar(0,255,0),2);
    putText(frame,intToString(x)+","+intToString(y),Point(x,y+32),1,1,Scalar(targetR,targetG,targetB),2);
    putText(frame, "id: " + intToString(robot.id), Point (x, y + 50), 1,1,Scalar(targetR,targetG,targetB),2);
    putText(frame, "FF: " + intToString(robot.first_frame), Point (x, y + 68), 1,1,Scalar(targetR,targetG,targetB),2);
    putText(frame, robot.robot_color, Point(x, y+86), 1, 1, Scalar(targetR,targetG,targetB), 2);
}


void trackFilteredObject(int &x, int &y, MainWindow::colors data, long N_curr_frame) {
    Mat temp;
    MainWindow m;
    data.threshold.copyTo(temp);
    std::vector< std::vector<Point> > contours;
    std::vector<Vec4i> hierarchy;
    findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE);

    if (hierarchy.size() > 0 && hierarchy.size() < MAX_NUM_OBJECTS) {
        for (int index = 0; index >= 0; index = hierarchy[index][0]) {
            Moments moment = moments((cv::Mat)contours[index]);
            double area = moment.m00;
            x = moment.m10/area;
            y = moment.m01/area;
            if (area > (m.min_object_size*m.min_object_size) && area < MAX_OBJECT_AREA) {
                bool is_new = true;
                for (size_t i = 0; i < objects.size(); i++) {
                    distance = getDistance(Point(x, y), objects[i].prev_coordinates);
                    if (distance < MIN_DIST) { // значит эта точка является точкой обьекта objects[i]
                        objects[i].curr_coordinates = Point(x, y);
                        objects[i].prev_coordinates = objects[i].curr_coordinates;

                        //objects[i].lastPoints.emplace_back(Point(x, y));
                        is_new = false;
                    }
                }
                if (is_new) { // вышло так, что это новый обьект, значит добавляем его
                    objects.emplace_back(N_curr_frame, (-1), data.color_name);
                    //objects[objects.size() - 1].lastPoints.emplace_back(Point(x, y));
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.readAndSet();
    w.show();
    VideoCapture capture;
    x = 0;
    y = 0;
    //fillMapDistances();
    capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
    Mat threshold, HSV;
    Mat cur_frame; // Mat3b aka Mat.at<Vec3b>
    w.colors_array[0].color_name = "red";
    w.colors_array[0].H_MAX = w.h1_max;
    w.colors_array[0].H_MIN = w.h1_min;

    w.colors_array[1].color_name = "green";
    w.colors_array[1].H_MAX = w.h2_max;
    w.colors_array[1].H_MIN = w.h2_min;

    w.colors_array[2].color_name = "blue";
    w.colors_array[2].H_MAX = w.h3_max;
    w.colors_array[2].H_MIN = w.h3_min;

    capture.open(PATH);
    while (1) {
        N_curr_frame = 0;

        capture.set(CV_CAP_PROP_POS_FRAMES, 0);
        capture.read(cur_frame);
        cvtColor(cur_frame, threshold, CV_BGR2HSV); // чтобы threshold пустым не был
        cvtColor(cur_frame, w.colors_array[0].threshold, CV_BGR2RGB);
        cvtColor(cur_frame, w.colors_array[1].threshold, CV_BGR2RGB);
        cvtColor(cur_frame, w.colors_array[2].threshold, CV_BGR2RGB);
        capture.set(CV_CAP_PROP_POS_FRAMES, 0);

        while (capture.get(CV_CAP_PROP_POS_FRAMES) < capture.get(CV_CAP_PROP_FRAME_COUNT)-20) {
            qApp->processEvents(); // без этой строчки ничего не запускается
            capture.read(cur_frame);
            cvtColor(cur_frame, HSV, CV_BGR2HSV);

            w.colors_array[0].H_MAX = w.h1_max;
            w.colors_array[0].H_MIN = w.h1_min;

            w.colors_array[1].H_MAX = w.h2_max;
            w.colors_array[1].H_MIN = w.h2_min;

            w.colors_array[2].H_MAX = w.h3_max;
            w.colors_array[2].H_MIN = w.h3_min;

            for (int i = 0; i < 3; i++) {
                inRange(HSV, Scalar(w.colors_array[i].H_MIN,w.s_min,w.v_min),
                        Scalar(w.colors_array[i].H_MAX,w.s_max,w.v_max),w.colors_array[i].threshold);
                trackFilteredObject(x, y, w.colors_array[i], N_curr_frame);
                w.filterThreshold(w.colors_array[i].threshold);
            }

            w.form_threshold(cur_frame);

            if (w.if_checked(CHECKBOX_TRACKING)) {
                for (size_t index = 0; index < objects.size(); index++) {
                    if (getDistance(objects[index].curr_coordinates, objects[index].prev_coordinates) <= 1.5) {
                        objects[index].curr_coordinates = objects[index].prev_coordinates;
                    }
                    // рисуем те обьекты, которые не удалили ранее
                    drawObject(objects[index].curr_coordinates.x, objects[index].curr_coordinates.y, cur_frame, cur_frame, objects[index]);
                }
            }
            if (w.id_ready) {
                for (size_t index = 0; index < objects.size(); index++) {
                    if (objects[index].id == -1) {
                        objects[index].id = (w.ui->lineEdit->text()).toInt();
                    }
                }
                w.id_ready = false;
            }
            N_curr_frame++;
            cvtColor(cur_frame, cur_frame, CV_BGR2RGB);
            w.displayImage(cur_frame, LABEL_NOFILTER);
            waitKey(20);
        }
    }
    w.show();
    return a.exec();
}
