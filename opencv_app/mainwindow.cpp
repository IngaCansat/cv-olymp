#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>
#include <QTextStream>
#include <QCloseEvent>
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->H1_max_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));
    connect(ui->H1_min_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));

    connect(ui->H2_max_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));
    connect(ui->H2_min_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));

    connect(ui->H3_max_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));
    connect(ui->H3_min_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));

    connect(ui->S_max_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));
    connect(ui->S_min_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));

    connect(ui->V_max_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));
    connect(ui->V_min_slider, SIGNAL(valueChanged(int)), this, SLOT(setHSV()));

    connect(ui->quit_pushButton, SIGNAL(clicked()), this, SLOT(saveSliderData()));
    connect(ui->quit_pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setValueToLabel() {
    ui->H1_max_value_lbl->setText(QString::number(h1_max));
    ui->H1_min_value_lbl->setText(QString::number(h1_min));

    ui->H2_max_value_lbl->setText(QString::number(h2_max));
    ui->H2_min_value_lbl->setText(QString::number(h2_min));

    ui->H3_max_value_lbl->setText(QString::number(h3_max));
    ui->H3_min_value_lbl->setText(QString::number(h3_min));

    ui->S_max_value_lbl->setText(QString::number(s_max));
    ui->S_min_value_lbl->setText(QString::number(s_min));

    ui->V_max_value_lbl->setText(QString::number(v_max));
    ui->V_min_value_lbl->setText(QString::number(v_min));
}

// TODO: setHSV только для измененного слайдера
void MainWindow::setHSV() {
    h1_max = ui->H1_max_slider->value();
    h1_min = ui->H1_min_slider->value();

    h2_max = ui->H2_max_slider->value();
    h2_min = ui->H2_min_slider->value();

    h3_max = ui->H3_max_slider->value();
    h3_min = ui->H3_min_slider->value();

    s_max = ui->S_max_slider->value();
    s_min = ui->S_min_slider->value();

    v_max = ui->V_max_slider->value();
    v_min = ui->V_min_slider->value();

    setValueToLabel();
}

void MainWindow::saveSliderData() {
    QFile fileIn("/Users/inga/Desktop/MSHP/filein.txt");
    int SliderData[] = { h1_max, h1_min, h2_max, h2_min,
                         h3_max, h3_min, s_max, s_min,
                         v_max, v_min };
    int NumOfSliderParameters = 10;
    if(fileIn.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream writeStream(&fileIn);
        for (int i = 0; i < NumOfSliderParameters; i++) {
            writeStream << QString::number(SliderData[i]);
            writeStream << "\n";
        }
        fileIn.close();
    }
}

void MainWindow::readAndSet() {
    QFile fileIn("/Users/inga/Desktop/MSHP/filein.txt");
    QString str;
    if(fileIn.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream readStream(&fileIn);
        readStream >> str;
        ui->H1_max_slider->setValue(str.split("\n")[0].toInt());
        readStream >> str;
        ui->H1_min_slider->setValue(str.split("\n")[0].toInt());

        readStream >> str;
        ui->H2_max_slider->setValue(str.split("\n")[0].toInt());
        readStream >> str;
        ui->H2_min_slider->setValue(str.split("\n")[0].toInt());

        readStream >> str;
        ui->H3_max_slider->setValue(str.split("\n")[0].toInt());
        readStream >> str;
        ui->H3_min_slider->setValue(str.split("\n")[0].toInt());

        readStream >> str;
        ui->S_max_slider->setValue(str.split("\n")[0].toInt());
        readStream >> str;
        ui->S_min_slider->setValue(str.split("\n")[0].toInt());

        readStream >> str;
        ui->V_max_slider->setValue(str.split("\n")[0].toInt());
        readStream >> str;
        ui->V_min_slider->setValue(str.split("\n")[0].toInt());

        fileIn.close();
    }
}

void MainWindow::filterThreshold(Mat& threshold) {
    Mat erodeElement = getStructuringElement( MORPH_RECT,Size(4,4));
    Mat dilateElement = getStructuringElement( MORPH_RECT,Size(5,7));
    erode(threshold,threshold,erodeElement); // the erosion makes the object in white smaller
    erode(threshold,threshold,erodeElement);
    dilate(threshold,threshold,dilateElement); // the dilation makes the object in white bigger
    dilate(threshold,threshold,dilateElement);
}

// эта функция вызывается раз в кадр
void MainWindow::form_threshold(Mat cur_frame) {
    int h,s,v,r,g,b;
    Mat hsv;
    // cur_frame в hsv
    cvtColor(cur_frame, thresh, CV_BGR2HSV);
    cvtColor(cur_frame, hsv, CV_BGR2HSV);
    for(int j = 0; j < thresh.rows; j += 1) {
        for(int i = 0; i < thresh.cols; i += 1) {
            h = 0, s = 0, v = 0;
            r = 0, g = 0, b = 0;
            Vec3b hsv_pixel = thresh.at<Vec3b>(Point(i, j));
            h = hsv_pixel.val[0];
            s = hsv_pixel.val[1];
            v = hsv_pixel.val[2];
            g = (s >= s_min) && (s <= s_max) ? 255 : 0;
            b = (v >= v_min) && (v <= v_max) ? 255 : 0;

            if (if_checked(CHECKBOX_THRESHOLD)) {
                thresh.at<Vec3b>(Point(i, j)) = Vec3b(0, g, b);
                if (i == thresh.cols - 1 && j == thresh.rows - 1) {
                    displayImage(thresh, LABEL_THRESHOLD);
                }
            }

            if (i == thresh.cols - 1 && j == thresh.rows - 1) {
                if (if_checked(CHECK_BOX_H1_ENABLE)) {
                    displayImage(colors_array[0].threshold, LABEL_H1_THRESHOLD);
                }
                if (if_checked(CHECK_BOX_H2_ENABLE)) {
                    displayImage(colors_array[1].threshold, LABEL_H2_THRESHOLD);
                }
                if (if_checked(CHECK_BOX_H3_ENABLE)) {
                    displayImage(colors_array[2].threshold, LABEL_H3_THRESHOLD);
                }
            }
        } // не трогай эту скобочку!
    } // и эту не трогай!
}

void MainWindow::displayImage(cv::Mat img, lbl_name_t label) {
    // cv::Mat 2 QImage
    QImage QImg;
    if (label == LABEL_H1_THRESHOLD || label == LABEL_H2_THRESHOLD || label == LABEL_H3_THRESHOLD) {
        QImg = QImage((const unsigned char*)(img.data),
                        img.cols,img.rows,
                        QImage::Format_Grayscale8);
    }
    else {
        QImg = QImage((const unsigned char*)(img.data),
                        img.cols,img.rows,
                        QImage::Format_RGB888);
    }
    int w, h;
    if (label == LABEL_NOFILTER) {
        w = ui->nofilter_video_label->width();
        h = ui->nofilter_video_label->height();
        ui->nofilter_video_label->setPixmap(QPixmap::fromImage(QImg).scaled(w, h, Qt::IgnoreAspectRatio));
        ui->nofilter_video_label->resize(ui->nofilter_video_label->pixmap()->size());
    }
    else if (label == LABEL_THRESHOLD) {
        w = ui->threshold_video_label->width();
        h = ui->threshold_video_label->height();
        ui->threshold_video_label->setPixmap(QPixmap::fromImage(QImg).scaled(w, h, Qt::IgnoreAspectRatio));
        ui->threshold_video_label->resize(ui->threshold_video_label->pixmap()->size());
    }
    else if (label == LABEL_H1_THRESHOLD){
        w = ui->H1_threshold->width();
        h = ui->H1_threshold->height();
        ui->H1_threshold->setPixmap(QPixmap::fromImage(QImg).scaled(w, h, Qt::IgnoreAspectRatio));
        ui->H1_threshold->resize(ui->H1_threshold->pixmap()->size());
    }
    else if (label == LABEL_H2_THRESHOLD) {
        w = ui->H2_threshold->width();
        h = ui->H2_threshold->height();
        ui->H2_threshold->setPixmap(QPixmap::fromImage(QImg).scaled(w, h, Qt::IgnoreAspectRatio));
        ui->H2_threshold->resize(ui->H2_threshold->pixmap()->size());
    }
    else if (label == LABEL_H3_THRESHOLD) {
        w = ui->H3_threshold->width();
        h = ui->H3_threshold->height();
        ui->H3_threshold->setPixmap(QPixmap::fromImage(QImg).scaled(w, h, Qt::IgnoreAspectRatio));
        ui->H3_threshold->resize(ui->H3_threshold->pixmap()->size());
    }
}

bool MainWindow::if_checked(checkbox_name_t checkbox) {
    if (checkbox == CHECKBOX_TRACKING)
        return ui->tracking_checkBox->isChecked();
    else if (checkbox == CHECKBOX_THRESHOLD)
        return ui->threshold_checkBox->isChecked();
    else if (checkbox == CHECK_BOX_H1_ENABLE)
        return ui->H1_enable_checkBox->isChecked();
    else if (checkbox == CHECK_BOX_H2_ENABLE)
        return ui->H2_enable_checkBox->isChecked();
    else if (checkbox == CHECK_BOX_H3_ENABLE)
        return ui->H3_enable_checkBox->isChecked();
}
