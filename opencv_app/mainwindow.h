#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <opencv2/opencv.hpp>
#include "header.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void displayImage(cv::Mat img, lbl_name_t label);
        bool if_checked(checkbox_name_t checkbox);
        int h1_max = 0, h1_min = 0, h2_max = 0, h2_min = 0,
            h3_max = 0, h3_min = 0, s_max = 0, s_min = 0,
            v_max = 0, v_min = 0;
        int min_object_size = 20;
        Mat thresh;
        void readAndSet();
        struct colors {
            cv::String color_name;
            int H_MAX;
            int H_MIN;
            Mat threshold;
        };
        colors colors_array[3];
        void form_threshold(Mat cur_frame);
        void filterThreshold(Mat& threshold);
        bool id_ready = false;
        Ui::MainWindow *ui;

    public slots:
        void setHSV();
        void setValueToLabel();
        void saveSliderData();
        void send_id();
    signals:
        void valueChanged(int newValue);
};

#endif // MAINWINDOW_H

