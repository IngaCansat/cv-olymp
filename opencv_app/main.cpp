#include "mainwindow.h"

#define PATH "/Users/inga/Desktop/MSHP/Untitled.mov"
#define FRAME_WIDTH 720
#define FRAME_HEIGHT 480
#define MAX_NUM_OBJECTS 500
#define MAX_OBJECT_AREA FRAME_HEIGHT*FRAME_WIDTH/1.5

enum modes {
    NO_USB_CAM = 0,
    USB_CAM,
};
enum states {
    READ_MAP = 0,
    JUST_TRACKING,
    TRACKING_AND_SENDING
};

using namespace cv;

int x = 0, y = 0;
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
    int curr_line_coordinates;
    // хранит расстояние от данного обьекта до каждого существующего
    std::vector <double> distBetween;
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

// если появился новый обьект с нормальной площадью, то нужно определить,
// является ли он новым, или это просто новая точка уже существующего обьекта.
// так вот, если расстояние от потенциального обьекта до какого-нибудь из существующих
// обьектов > этой переменной, то этот обьект является новым
int MIN_DIST = 50;

// вектор всех обьектов, которые подходят по площади
// и которые находятся достаточно далеко от уже существующих обьетов
std::vector <Robot> objects;

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

std:: vector <Point> map_points;

int find_line_coordinates (Robot robot) {
    Point closest1, closest2;
    double min_dist = 5000;
    int i_of_min;
    double min_dist2 = 5000;
    for (size_t i = 0; i < map_points.size(); i++) {
        double dist = getDistance(robot.curr_coordinates, map_points[i]);
        if (dist < min_dist) {
            min_dist = dist;
            closest1 = map_points[i];
            i_of_min = i;
        }
        //if (dist < min_dist2 && i != i_of_min) {
            //min_dist2 = dist;
            //closest2 = map_points[i];
        //}
    }
    return std::find(map_points.begin(), map_points.end(), closest1) - map_points.begin();

}

void drawObject (int x, int y, Mat &frame, Mat cameraFeed, Robot robot, color_t color) {
    int targetR = 0, targetG = 0, targetB = 0;
    switch(color) {
        case RED:
            targetR = 255;
            break;
        case GREEN:
            targetG = 255;
            break;
        case BLUE:
            targetB = 255;
            break;

    }
    circle(cameraFeed,Point(x,y),20,Scalar(targetB,targetG,targetR),2);
    putText(frame, intToString(robot.curr_line_coordinates), Point(x,y+32),1,1,Scalar(targetB,targetG,targetR),2);
    putText(frame, "id: " + intToString(robot.id), Point (x, y + 50), 1,1,Scalar(targetB,targetG,targetR),2);
    putText(frame, "FF: " + intToString(robot.first_frame), Point (x, y + 68), 1,1,Scalar(targetB,targetG,targetR),2);
    putText(frame, robot.robot_color, Point(x, y+86), 1, 1, Scalar(targetB,targetG,targetR), 2);
}

std::vector <Robot> waitingList;

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
                        size_t p = find_line_coordinates(objects[i]);
                        if (p >= map_points.size()/2)
                            objects[i].curr_line_coordinates = map_points.size() - p;
                        else
                            objects[i].curr_line_coordinates = p;
                        objects[i].prev_coordinates = objects[i].curr_coordinates;
                        is_new = false;
                    }
                }
                for (size_t i = 0; i < waitingList.size(); i++) {
                    distance = getDistance(Point(x, y), waitingList[i].prev_coordinates);
                    if (distance < MIN_DIST) { // значит эта точка является точкой обьекта waitingList[i]
                        waitingList[i].curr_coordinates = Point(x, y);
                        size_t p = find_line_coordinates(waitingList[i]);
                        if (p >= map_points.size()/2)
                            waitingList[i].curr_line_coordinates = map_points.size() - p;
                        else
                            waitingList[i].curr_line_coordinates = p;
                        waitingList[i].prev_coordinates = waitingList[i].curr_coordinates;
                        is_new = false;
                    }
                }
                if (is_new) {
                    waitingList.emplace_back(N_curr_frame, (-1), data.color_name);
                }
            }
        }
    }
}

int numMapPoints = 0;

void writeMapPoints(int mapX, int mapY) {
    QFile fileIn("/Users/inga/Desktop/MSHP/map.txt");
    QTextStream writeStream(&fileIn);
    if (fileIn.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        writeStream << QString::number(mapX);
        writeStream << " ";
        writeStream << QString::number(mapY);
        writeStream << " ";
        fileIn.close();
    }
}

void readAllMapPoints() {
    QFile fileOut("/Users/inga/Desktop/MSHP/map.txt");
    QTextStream readStream(&fileOut);
    QString str;
    Point p;
    int mapX, mapY;
    if (fileOut.open(QIODevice::ReadOnly | QIODevice::Text)) {
        readStream >> str;
        for (int i = 0; i < numMapPoints; i++) {
            mapX = str.split(" ")[0].toInt();
            mapY = str.split(" ")[0].toInt();
            p = Point(mapX, mapY);
            map_points.push_back(p);
        }

        fileOut.close();
    }
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    /*QString url = "http://localhost/test1.php?id=";
    int enable = 0;
    int id = 5;
    int x = 89;
    int y = 99;

    url.append(QString::number(id)); url.append("&x="); url.append(QString::number(x)); url.append("&y=");
    url.append(QString::number(y)); url.append("&enable="); url.append(QString::number(enable));
    w.request.setUrl(QUrl(url));
    w.manager->get(w.request);*/

    w.readAndSet();
    w.show();

    VideoCapture capture;
    Mat threshold, HSV, cur_frame;
    x = 0;
    y = 0;
    long k = 0; //!!! debug
    long N_curr_frame = 0;

    capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
    capture.set(CV_CAP_PROP_POS_FRAMES, 0);
    //capture.set(CV_CAP_PROP_EXPOSURE, 0.5);
    capture.set(CV_CAP_PROP_BRIGHTNESS, 0.1);
    //capture.set(CV_CAP_PROP_GAIN, 1);

    w.colors_array[0].color_name = "red";
    w.colors_array[0].H_MAX = w.h1_max;
    w.colors_array[0].H_MIN = w.h1_min;

    w.colors_array[1].color_name = "green";
    w.colors_array[1].H_MAX = w.h2_max;
    w.colors_array[1].H_MIN = w.h2_min;

    w.colors_array[2].color_name = "blue";
    w.colors_array[2].H_MAX = w.h3_max;
    w.colors_array[2].H_MIN = w.h3_min;

    int mode = USB_CAM;
    int state = JUST_TRACKING;
    int trackerID = 9;

    /*writeMapPoints(0, 0);
    writeMapPoints(4, 5);
    writeMapPoints(3, 5);

    writeMapPoints(2, 56);

    writeMapPoints(5, 77);
    readAllMapPoints();*/

    switch (mode) {

    case NO_USB_CAM:
        capture.open(PATH);
        while (1) {
            N_curr_frame = 0;
            capture.read(cur_frame);
            cvtColor(cur_frame, threshold, CV_BGR2HSV); // чтобы threshold пустым не был
            cvtColor(cur_frame, w.colors_array[0].threshold, CV_BGR2RGB);
            cvtColor(cur_frame, w.colors_array[1].threshold, CV_BGR2RGB);
            cvtColor(cur_frame, w.colors_array[2].threshold, CV_BGR2RGB);
            capture.set(CV_CAP_PROP_POS_FRAMES, 0);

            while (capture.get(CV_CAP_PROP_POS_FRAMES) < capture.get(CV_CAP_PROP_FRAME_COUNT)-20) {
                qApp->processEvents();
                if (w.done)
                    std::cout << 1 << std::endl;
                else
                    std::cout << 0 << std::endl;
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

                for (size_t index = 0; index < waitingList.size(); index++) {
                    if (N_curr_frame - waitingList[index].first_frame > 3*30) {
                        if (waitingList[index].id != -1) {
                            objects.push_back(waitingList[index]);
                        }
                        waitingList.erase(waitingList.begin()+index);
                    }
                    else {
                        if (w.id_ready && waitingList[index].id == -1) {
                            waitingList[index].id = (w.ui->lineEdit->text()).toInt();
                        }
                        w.id_ready = false;
                    }
                    if (w.if_checked(CHECKBOX_TRACKING)) {
                        drawObject(waitingList[index].curr_coordinates.x, waitingList[index].curr_coordinates.y,
                                   cur_frame, cur_frame, waitingList[index], RED);
                    }
                }

                for (size_t index = 0; index < objects.size(); index++) {
                    if (getDistance(objects[index].curr_coordinates, objects[index].prev_coordinates) <= 1.5) {
                        objects[index].curr_coordinates = objects[index].prev_coordinates;
                    }
                    if (w.if_checked(CHECKBOX_TRACKING)) {
                        if (state == READ_MAP) {
                            if (w.done) {
                                state = JUST_TRACKING;
                                w.done = false;
                                readAllMapPoints();
                            }
                            else {
                                if (objects[index].id == trackerID) {
                                    if (k % 8 == 0) {
                                        writeMapPoints(objects[index].curr_coordinates.x, objects[index].curr_coordinates.y);
                                    }
                                    k++;
                                    std::cout << k << endl;
                                }
                            }
                        }
                        drawObject(objects[index].curr_coordinates.x, objects[index].curr_coordinates.y,
                                   cur_frame, cur_frame, objects[index], GREEN);
                    }
                }

                N_curr_frame++;
                cvtColor(cur_frame, cur_frame, CV_BGR2RGB);
                w.displayImage(cur_frame, LABEL_NOFILTER);
                waitKey(20);
            }
        }
        break;

    case USB_CAM:
        capture.open(0);
        while (1) {
            qApp->processEvents();
            capture >> cur_frame;
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

            for (size_t index = 0; index < waitingList.size(); index++) {
                if (N_curr_frame - waitingList[index].first_frame > 30) {
                    if (waitingList[index].id != -1) {
                        objects.push_back(waitingList[index]);
                    }
                    waitingList.erase(waitingList.begin()+index);
                }
                else {
                    if (w.id_ready && waitingList[index].id == -1) {
                        waitingList[index].id = (w.ui->lineEdit->text()).toInt();
                    }
                    w.id_ready = false;
                }
                if (w.if_checked(CHECKBOX_TRACKING)) {
                    drawObject(waitingList[index].curr_coordinates.x, waitingList[index].curr_coordinates.y,
                               cur_frame, cur_frame, waitingList[index], RED);
                }
            }

            for (size_t index = 0; index < objects.size(); index++) {
                if (getDistance(objects[index].curr_coordinates, objects[index].prev_coordinates) <= 1.5) {
                    objects[index].curr_coordinates = objects[index].prev_coordinates;
                }
                if (w.if_checked(CHECKBOX_TRACKING)) {
                    if (state == READ_MAP) {
                        if (w.done) {
                            state = JUST_TRACKING;
                            w.done = false;
                            readAllMapPoints();
                        }
                        else {
                            if (objects[index].id == trackerID) {
                                if (k % 8 == 0) {
                                    writeMapPoints(objects[index].curr_coordinates.x, objects[index].curr_coordinates.y);
                                }
                                k++;
                                std::cout << k << endl;
                            }
                        }
                    }
                    drawObject(objects[index].curr_coordinates.x, objects[index].curr_coordinates.y,
                               cur_frame, cur_frame, objects[index], GREEN);
                }
            }

            N_curr_frame++;
            cvtColor(cur_frame, cur_frame, CV_BGR2RGB);
            w.displayImage(cur_frame, LABEL_NOFILTER);
            waitKey(60);
        }
        break;
    }
    return a.exec();
}
