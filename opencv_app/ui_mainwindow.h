/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *main_verticalLayout;
    QVBoxLayout *videos_verticalLayout;
    QLabel *nofilter_video_label;
    QLabel *threshold_video_label;
    QHBoxLayout *checkboxes;
    QCheckBox *tracking_checkBox;
    QPushButton *quit_pushButton;
    QLineEdit *lineEdit;
    QPushButton *send_pushButton;
    QPushButton *done_pushButton;
    QCheckBox *threshold_checkBox;
    QVBoxLayout *SV_sliders_verticalLayout;
    QHBoxLayout *Size_horizontalLayout;
    QLabel *Size_lbl;
    QSlider *Size_slider;
    QLabel *Size_value_lbl;
    QHBoxLayout *S_max_horizontalLayout;
    QLabel *S_max_lbl;
    QSlider *S_max_slider;
    QLabel *S_max_value_lbl;
    QHBoxLayout *S_min_horizontalLayout;
    QLabel *S_min_lbl;
    QSlider *S_min_slider;
    QLabel *S_min_value_lbl;
    QHBoxLayout *V_max_horizontalLayout;
    QLabel *V_max_lbl;
    QSlider *V_max_slider;
    QLabel *V_max_value_lbl;
    QHBoxLayout *V_min_horizontalLayout;
    QLabel *V_min_lbl;
    QSlider *V_min_slider;
    QLabel *V_min_value_lbl;
    QGridLayout *slider_gridLayout;
    QVBoxLayout *H2_adjustments_block;
    QLabel *H2_threshold;
    QHBoxLayout *H2_block;
    QVBoxLayout *H2_slider_block;
    QHBoxLayout *H2_max_slider_block;
    QLabel *H2_max_lbl;
    QSlider *H2_max_slider;
    QLabel *H2_max_value_lbl;
    QHBoxLayout *H2_min_slider_block;
    QLabel *H2_min_lbl;
    QSlider *H2_min_slider;
    QLabel *H2_min_value_lbl;
    QCheckBox *H2_enable_checkBox;
    QVBoxLayout *H3_adjustments_block;
    QLabel *H3_threshold;
    QHBoxLayout *H3_block;
    QVBoxLayout *H3_slider_block;
    QHBoxLayout *H3_max_slider_block;
    QLabel *H_max_lbl;
    QSlider *H3_max_slider;
    QLabel *H3_max_value_lbl;
    QHBoxLayout *H3_min_slider_block;
    QLabel *H3_min_lbl;
    QSlider *H3_min_slider;
    QLabel *H3_min_value_lbl;
    QCheckBox *H3_enable_checkBox;
    QVBoxLayout *H1_adjustments_block;
    QLabel *H1_threshold;
    QHBoxLayout *H1_block;
    QVBoxLayout *H1_slider_block;
    QHBoxLayout *H1_max_slider_block;
    QLabel *H1_max_lbl;
    QSlider *H1_max_slider;
    QLabel *H1_max_value_lbl;
    QHBoxLayout *H1_min_slider_block;
    QLabel *H1_min_lbl;
    QSlider *H1_min_slider;
    QLabel *H1_min_value_lbl;
    QCheckBox *H1_enable_checkBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(871, 671);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        main_verticalLayout = new QVBoxLayout();
        main_verticalLayout->setSpacing(6);
        main_verticalLayout->setObjectName(QStringLiteral("main_verticalLayout"));
        videos_verticalLayout = new QVBoxLayout();
        videos_verticalLayout->setSpacing(6);
        videos_verticalLayout->setObjectName(QStringLiteral("videos_verticalLayout"));
        nofilter_video_label = new QLabel(centralWidget);
        nofilter_video_label->setObjectName(QStringLiteral("nofilter_video_label"));
        nofilter_video_label->setStyleSheet(QStringLiteral(""));

        videos_verticalLayout->addWidget(nofilter_video_label);

        threshold_video_label = new QLabel(centralWidget);
        threshold_video_label->setObjectName(QStringLiteral("threshold_video_label"));
        threshold_video_label->setStyleSheet(QStringLiteral(""));

        videos_verticalLayout->addWidget(threshold_video_label);


        main_verticalLayout->addLayout(videos_verticalLayout);

        checkboxes = new QHBoxLayout();
        checkboxes->setSpacing(6);
        checkboxes->setObjectName(QStringLiteral("checkboxes"));
        tracking_checkBox = new QCheckBox(centralWidget);
        tracking_checkBox->setObjectName(QStringLiteral("tracking_checkBox"));

        checkboxes->addWidget(tracking_checkBox);

        quit_pushButton = new QPushButton(centralWidget);
        quit_pushButton->setObjectName(QStringLiteral("quit_pushButton"));

        checkboxes->addWidget(quit_pushButton);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        checkboxes->addWidget(lineEdit);

        send_pushButton = new QPushButton(centralWidget);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));

        checkboxes->addWidget(send_pushButton);

        done_pushButton = new QPushButton(centralWidget);
        done_pushButton->setObjectName(QStringLiteral("done_pushButton"));

        checkboxes->addWidget(done_pushButton);

        threshold_checkBox = new QCheckBox(centralWidget);
        threshold_checkBox->setObjectName(QStringLiteral("threshold_checkBox"));

        checkboxes->addWidget(threshold_checkBox);


        main_verticalLayout->addLayout(checkboxes);

        SV_sliders_verticalLayout = new QVBoxLayout();
        SV_sliders_verticalLayout->setSpacing(6);
        SV_sliders_verticalLayout->setObjectName(QStringLiteral("SV_sliders_verticalLayout"));
        Size_horizontalLayout = new QHBoxLayout();
        Size_horizontalLayout->setSpacing(6);
        Size_horizontalLayout->setObjectName(QStringLiteral("Size_horizontalLayout"));
        Size_lbl = new QLabel(centralWidget);
        Size_lbl->setObjectName(QStringLiteral("Size_lbl"));
        Size_lbl->setMinimumSize(QSize(50, 0));

        Size_horizontalLayout->addWidget(Size_lbl);

        Size_slider = new QSlider(centralWidget);
        Size_slider->setObjectName(QStringLiteral("Size_slider"));
        Size_slider->setMinimum(0);
        Size_slider->setMaximum(100);
        Size_slider->setOrientation(Qt::Horizontal);

        Size_horizontalLayout->addWidget(Size_slider);

        Size_value_lbl = new QLabel(centralWidget);
        Size_value_lbl->setObjectName(QStringLiteral("Size_value_lbl"));
        Size_value_lbl->setMinimumSize(QSize(40, 0));

        Size_horizontalLayout->addWidget(Size_value_lbl);


        SV_sliders_verticalLayout->addLayout(Size_horizontalLayout);

        S_max_horizontalLayout = new QHBoxLayout();
        S_max_horizontalLayout->setSpacing(6);
        S_max_horizontalLayout->setObjectName(QStringLiteral("S_max_horizontalLayout"));
        S_max_lbl = new QLabel(centralWidget);
        S_max_lbl->setObjectName(QStringLiteral("S_max_lbl"));
        S_max_lbl->setMinimumSize(QSize(50, 0));

        S_max_horizontalLayout->addWidget(S_max_lbl);

        S_max_slider = new QSlider(centralWidget);
        S_max_slider->setObjectName(QStringLiteral("S_max_slider"));
        S_max_slider->setMaximum(255);
        S_max_slider->setPageStep(10);
        S_max_slider->setOrientation(Qt::Horizontal);

        S_max_horizontalLayout->addWidget(S_max_slider);

        S_max_value_lbl = new QLabel(centralWidget);
        S_max_value_lbl->setObjectName(QStringLiteral("S_max_value_lbl"));
        S_max_value_lbl->setMinimumSize(QSize(40, 0));

        S_max_horizontalLayout->addWidget(S_max_value_lbl);


        SV_sliders_verticalLayout->addLayout(S_max_horizontalLayout);

        S_min_horizontalLayout = new QHBoxLayout();
        S_min_horizontalLayout->setSpacing(6);
        S_min_horizontalLayout->setObjectName(QStringLiteral("S_min_horizontalLayout"));
        S_min_lbl = new QLabel(centralWidget);
        S_min_lbl->setObjectName(QStringLiteral("S_min_lbl"));
        S_min_lbl->setMinimumSize(QSize(50, 0));

        S_min_horizontalLayout->addWidget(S_min_lbl);

        S_min_slider = new QSlider(centralWidget);
        S_min_slider->setObjectName(QStringLiteral("S_min_slider"));
        S_min_slider->setMaximum(255);
        S_min_slider->setOrientation(Qt::Horizontal);

        S_min_horizontalLayout->addWidget(S_min_slider);

        S_min_value_lbl = new QLabel(centralWidget);
        S_min_value_lbl->setObjectName(QStringLiteral("S_min_value_lbl"));
        S_min_value_lbl->setMinimumSize(QSize(40, 0));

        S_min_horizontalLayout->addWidget(S_min_value_lbl);


        SV_sliders_verticalLayout->addLayout(S_min_horizontalLayout);

        V_max_horizontalLayout = new QHBoxLayout();
        V_max_horizontalLayout->setSpacing(6);
        V_max_horizontalLayout->setObjectName(QStringLiteral("V_max_horizontalLayout"));
        V_max_lbl = new QLabel(centralWidget);
        V_max_lbl->setObjectName(QStringLiteral("V_max_lbl"));
        V_max_lbl->setMinimumSize(QSize(50, 0));

        V_max_horizontalLayout->addWidget(V_max_lbl);

        V_max_slider = new QSlider(centralWidget);
        V_max_slider->setObjectName(QStringLiteral("V_max_slider"));
        V_max_slider->setMaximum(255);
        V_max_slider->setOrientation(Qt::Horizontal);

        V_max_horizontalLayout->addWidget(V_max_slider);

        V_max_value_lbl = new QLabel(centralWidget);
        V_max_value_lbl->setObjectName(QStringLiteral("V_max_value_lbl"));
        V_max_value_lbl->setMinimumSize(QSize(40, 0));

        V_max_horizontalLayout->addWidget(V_max_value_lbl);


        SV_sliders_verticalLayout->addLayout(V_max_horizontalLayout);

        V_min_horizontalLayout = new QHBoxLayout();
        V_min_horizontalLayout->setSpacing(6);
        V_min_horizontalLayout->setObjectName(QStringLiteral("V_min_horizontalLayout"));
        V_min_lbl = new QLabel(centralWidget);
        V_min_lbl->setObjectName(QStringLiteral("V_min_lbl"));
        V_min_lbl->setMinimumSize(QSize(50, 0));

        V_min_horizontalLayout->addWidget(V_min_lbl);

        V_min_slider = new QSlider(centralWidget);
        V_min_slider->setObjectName(QStringLiteral("V_min_slider"));
        V_min_slider->setMaximum(255);
        V_min_slider->setOrientation(Qt::Horizontal);

        V_min_horizontalLayout->addWidget(V_min_slider);

        V_min_value_lbl = new QLabel(centralWidget);
        V_min_value_lbl->setObjectName(QStringLiteral("V_min_value_lbl"));
        V_min_value_lbl->setMinimumSize(QSize(40, 0));

        V_min_horizontalLayout->addWidget(V_min_value_lbl);


        SV_sliders_verticalLayout->addLayout(V_min_horizontalLayout);


        main_verticalLayout->addLayout(SV_sliders_verticalLayout);

        main_verticalLayout->setStretch(0, 7);
        main_verticalLayout->setStretch(1, 1);
        main_verticalLayout->setStretch(2, 1);

        horizontalLayout_3->addLayout(main_verticalLayout);

        slider_gridLayout = new QGridLayout();
        slider_gridLayout->setSpacing(6);
        slider_gridLayout->setObjectName(QStringLiteral("slider_gridLayout"));
        slider_gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        H2_adjustments_block = new QVBoxLayout();
        H2_adjustments_block->setSpacing(6);
        H2_adjustments_block->setObjectName(QStringLiteral("H2_adjustments_block"));
        H2_threshold = new QLabel(centralWidget);
        H2_threshold->setObjectName(QStringLiteral("H2_threshold"));
        H2_threshold->setEnabled(true);

        H2_adjustments_block->addWidget(H2_threshold);

        H2_block = new QHBoxLayout();
        H2_block->setSpacing(6);
        H2_block->setObjectName(QStringLiteral("H2_block"));
        H2_slider_block = new QVBoxLayout();
        H2_slider_block->setSpacing(6);
        H2_slider_block->setObjectName(QStringLiteral("H2_slider_block"));
        H2_max_slider_block = new QHBoxLayout();
        H2_max_slider_block->setSpacing(6);
        H2_max_slider_block->setObjectName(QStringLiteral("H2_max_slider_block"));
        H2_max_lbl = new QLabel(centralWidget);
        H2_max_lbl->setObjectName(QStringLiteral("H2_max_lbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(H2_max_lbl->sizePolicy().hasHeightForWidth());
        H2_max_lbl->setSizePolicy(sizePolicy1);

        H2_max_slider_block->addWidget(H2_max_lbl);

        H2_max_slider = new QSlider(centralWidget);
        H2_max_slider->setObjectName(QStringLiteral("H2_max_slider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(H2_max_slider->sizePolicy().hasHeightForWidth());
        H2_max_slider->setSizePolicy(sizePolicy2);
        H2_max_slider->setMaximum(180);
        H2_max_slider->setOrientation(Qt::Horizontal);

        H2_max_slider_block->addWidget(H2_max_slider);

        H2_max_value_lbl = new QLabel(centralWidget);
        H2_max_value_lbl->setObjectName(QStringLiteral("H2_max_value_lbl"));
        sizePolicy1.setHeightForWidth(H2_max_value_lbl->sizePolicy().hasHeightForWidth());
        H2_max_value_lbl->setSizePolicy(sizePolicy1);

        H2_max_slider_block->addWidget(H2_max_value_lbl);


        H2_slider_block->addLayout(H2_max_slider_block);

        H2_min_slider_block = new QHBoxLayout();
        H2_min_slider_block->setSpacing(6);
        H2_min_slider_block->setObjectName(QStringLiteral("H2_min_slider_block"));
        H2_min_lbl = new QLabel(centralWidget);
        H2_min_lbl->setObjectName(QStringLiteral("H2_min_lbl"));
        sizePolicy1.setHeightForWidth(H2_min_lbl->sizePolicy().hasHeightForWidth());
        H2_min_lbl->setSizePolicy(sizePolicy1);

        H2_min_slider_block->addWidget(H2_min_lbl);

        H2_min_slider = new QSlider(centralWidget);
        H2_min_slider->setObjectName(QStringLiteral("H2_min_slider"));
        sizePolicy2.setHeightForWidth(H2_min_slider->sizePolicy().hasHeightForWidth());
        H2_min_slider->setSizePolicy(sizePolicy2);
        H2_min_slider->setMaximum(180);
        H2_min_slider->setOrientation(Qt::Horizontal);

        H2_min_slider_block->addWidget(H2_min_slider);

        H2_min_value_lbl = new QLabel(centralWidget);
        H2_min_value_lbl->setObjectName(QStringLiteral("H2_min_value_lbl"));
        sizePolicy1.setHeightForWidth(H2_min_value_lbl->sizePolicy().hasHeightForWidth());
        H2_min_value_lbl->setSizePolicy(sizePolicy1);

        H2_min_slider_block->addWidget(H2_min_value_lbl);


        H2_slider_block->addLayout(H2_min_slider_block);


        H2_block->addLayout(H2_slider_block);

        H2_enable_checkBox = new QCheckBox(centralWidget);
        H2_enable_checkBox->setObjectName(QStringLiteral("H2_enable_checkBox"));

        H2_block->addWidget(H2_enable_checkBox);

        H2_block->setStretch(0, 3);
        H2_block->setStretch(1, 1);

        H2_adjustments_block->addLayout(H2_block);

        H2_adjustments_block->setStretch(0, 3);

        slider_gridLayout->addLayout(H2_adjustments_block, 4, 1, 1, 1);

        H3_adjustments_block = new QVBoxLayout();
        H3_adjustments_block->setSpacing(6);
        H3_adjustments_block->setObjectName(QStringLiteral("H3_adjustments_block"));
        H3_threshold = new QLabel(centralWidget);
        H3_threshold->setObjectName(QStringLiteral("H3_threshold"));

        H3_adjustments_block->addWidget(H3_threshold);

        H3_block = new QHBoxLayout();
        H3_block->setSpacing(6);
        H3_block->setObjectName(QStringLiteral("H3_block"));
        H3_slider_block = new QVBoxLayout();
        H3_slider_block->setSpacing(6);
        H3_slider_block->setObjectName(QStringLiteral("H3_slider_block"));
        H3_max_slider_block = new QHBoxLayout();
        H3_max_slider_block->setSpacing(6);
        H3_max_slider_block->setObjectName(QStringLiteral("H3_max_slider_block"));
        H_max_lbl = new QLabel(centralWidget);
        H_max_lbl->setObjectName(QStringLiteral("H_max_lbl"));
        sizePolicy1.setHeightForWidth(H_max_lbl->sizePolicy().hasHeightForWidth());
        H_max_lbl->setSizePolicy(sizePolicy1);

        H3_max_slider_block->addWidget(H_max_lbl);

        H3_max_slider = new QSlider(centralWidget);
        H3_max_slider->setObjectName(QStringLiteral("H3_max_slider"));
        sizePolicy2.setHeightForWidth(H3_max_slider->sizePolicy().hasHeightForWidth());
        H3_max_slider->setSizePolicy(sizePolicy2);
        H3_max_slider->setMaximum(180);
        H3_max_slider->setOrientation(Qt::Horizontal);

        H3_max_slider_block->addWidget(H3_max_slider);

        H3_max_value_lbl = new QLabel(centralWidget);
        H3_max_value_lbl->setObjectName(QStringLiteral("H3_max_value_lbl"));
        sizePolicy1.setHeightForWidth(H3_max_value_lbl->sizePolicy().hasHeightForWidth());
        H3_max_value_lbl->setSizePolicy(sizePolicy1);

        H3_max_slider_block->addWidget(H3_max_value_lbl);


        H3_slider_block->addLayout(H3_max_slider_block);

        H3_min_slider_block = new QHBoxLayout();
        H3_min_slider_block->setSpacing(6);
        H3_min_slider_block->setObjectName(QStringLiteral("H3_min_slider_block"));
        H3_min_lbl = new QLabel(centralWidget);
        H3_min_lbl->setObjectName(QStringLiteral("H3_min_lbl"));
        sizePolicy1.setHeightForWidth(H3_min_lbl->sizePolicy().hasHeightForWidth());
        H3_min_lbl->setSizePolicy(sizePolicy1);

        H3_min_slider_block->addWidget(H3_min_lbl);

        H3_min_slider = new QSlider(centralWidget);
        H3_min_slider->setObjectName(QStringLiteral("H3_min_slider"));
        sizePolicy2.setHeightForWidth(H3_min_slider->sizePolicy().hasHeightForWidth());
        H3_min_slider->setSizePolicy(sizePolicy2);
        H3_min_slider->setMaximum(180);
        H3_min_slider->setOrientation(Qt::Horizontal);

        H3_min_slider_block->addWidget(H3_min_slider);

        H3_min_value_lbl = new QLabel(centralWidget);
        H3_min_value_lbl->setObjectName(QStringLiteral("H3_min_value_lbl"));
        sizePolicy1.setHeightForWidth(H3_min_value_lbl->sizePolicy().hasHeightForWidth());
        H3_min_value_lbl->setSizePolicy(sizePolicy1);

        H3_min_slider_block->addWidget(H3_min_value_lbl);


        H3_slider_block->addLayout(H3_min_slider_block);

        H3_slider_block->setStretch(0, 3);
        H3_slider_block->setStretch(1, 1);

        H3_block->addLayout(H3_slider_block);

        H3_enable_checkBox = new QCheckBox(centralWidget);
        H3_enable_checkBox->setObjectName(QStringLiteral("H3_enable_checkBox"));

        H3_block->addWidget(H3_enable_checkBox);

        H3_block->setStretch(0, 3);
        H3_block->setStretch(1, 1);

        H3_adjustments_block->addLayout(H3_block);

        H3_adjustments_block->setStretch(0, 3);

        slider_gridLayout->addLayout(H3_adjustments_block, 5, 1, 1, 1);

        H1_adjustments_block = new QVBoxLayout();
        H1_adjustments_block->setSpacing(0);
        H1_adjustments_block->setObjectName(QStringLiteral("H1_adjustments_block"));
        H1_adjustments_block->setSizeConstraint(QLayout::SetDefaultConstraint);
        H1_adjustments_block->setContentsMargins(-1, -1, -1, 0);
        H1_threshold = new QLabel(centralWidget);
        H1_threshold->setObjectName(QStringLiteral("H1_threshold"));

        H1_adjustments_block->addWidget(H1_threshold);

        H1_block = new QHBoxLayout();
        H1_block->setSpacing(6);
        H1_block->setObjectName(QStringLiteral("H1_block"));
        H1_slider_block = new QVBoxLayout();
        H1_slider_block->setSpacing(6);
        H1_slider_block->setObjectName(QStringLiteral("H1_slider_block"));
        H1_max_slider_block = new QHBoxLayout();
        H1_max_slider_block->setSpacing(6);
        H1_max_slider_block->setObjectName(QStringLiteral("H1_max_slider_block"));
        H1_max_lbl = new QLabel(centralWidget);
        H1_max_lbl->setObjectName(QStringLiteral("H1_max_lbl"));
        sizePolicy1.setHeightForWidth(H1_max_lbl->sizePolicy().hasHeightForWidth());
        H1_max_lbl->setSizePolicy(sizePolicy1);
        H1_max_lbl->setTextFormat(Qt::AutoText);

        H1_max_slider_block->addWidget(H1_max_lbl);

        H1_max_slider = new QSlider(centralWidget);
        H1_max_slider->setObjectName(QStringLiteral("H1_max_slider"));
        sizePolicy2.setHeightForWidth(H1_max_slider->sizePolicy().hasHeightForWidth());
        H1_max_slider->setSizePolicy(sizePolicy2);
        H1_max_slider->setMaximum(180);
        H1_max_slider->setOrientation(Qt::Horizontal);

        H1_max_slider_block->addWidget(H1_max_slider);

        H1_max_value_lbl = new QLabel(centralWidget);
        H1_max_value_lbl->setObjectName(QStringLiteral("H1_max_value_lbl"));
        sizePolicy1.setHeightForWidth(H1_max_value_lbl->sizePolicy().hasHeightForWidth());
        H1_max_value_lbl->setSizePolicy(sizePolicy1);

        H1_max_slider_block->addWidget(H1_max_value_lbl);


        H1_slider_block->addLayout(H1_max_slider_block);

        H1_min_slider_block = new QHBoxLayout();
        H1_min_slider_block->setSpacing(6);
        H1_min_slider_block->setObjectName(QStringLiteral("H1_min_slider_block"));
        H1_min_lbl = new QLabel(centralWidget);
        H1_min_lbl->setObjectName(QStringLiteral("H1_min_lbl"));
        sizePolicy1.setHeightForWidth(H1_min_lbl->sizePolicy().hasHeightForWidth());
        H1_min_lbl->setSizePolicy(sizePolicy1);

        H1_min_slider_block->addWidget(H1_min_lbl);

        H1_min_slider = new QSlider(centralWidget);
        H1_min_slider->setObjectName(QStringLiteral("H1_min_slider"));
        sizePolicy2.setHeightForWidth(H1_min_slider->sizePolicy().hasHeightForWidth());
        H1_min_slider->setSizePolicy(sizePolicy2);
        H1_min_slider->setMaximum(180);
        H1_min_slider->setOrientation(Qt::Horizontal);

        H1_min_slider_block->addWidget(H1_min_slider);

        H1_min_value_lbl = new QLabel(centralWidget);
        H1_min_value_lbl->setObjectName(QStringLiteral("H1_min_value_lbl"));
        sizePolicy1.setHeightForWidth(H1_min_value_lbl->sizePolicy().hasHeightForWidth());
        H1_min_value_lbl->setSizePolicy(sizePolicy1);

        H1_min_slider_block->addWidget(H1_min_value_lbl);


        H1_slider_block->addLayout(H1_min_slider_block);


        H1_block->addLayout(H1_slider_block);

        H1_enable_checkBox = new QCheckBox(centralWidget);
        H1_enable_checkBox->setObjectName(QStringLiteral("H1_enable_checkBox"));

        H1_block->addWidget(H1_enable_checkBox);

        H1_block->setStretch(0, 3);
        H1_block->setStretch(1, 1);

        H1_adjustments_block->addLayout(H1_block);

        H1_adjustments_block->setStretch(0, 3);

        slider_gridLayout->addLayout(H1_adjustments_block, 0, 1, 1, 1);


        horizontalLayout_3->addLayout(slider_gridLayout);

        horizontalLayout_3->setStretch(0, 6);
        horizontalLayout_3->setStretch(1, 5);

        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 871, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(H1_max_slider, H1_min_slider);
        QWidget::setTabOrder(H1_min_slider, S_max_slider);
        QWidget::setTabOrder(S_max_slider, S_min_slider);
        QWidget::setTabOrder(S_min_slider, V_max_slider);
        QWidget::setTabOrder(V_max_slider, V_min_slider);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        nofilter_video_label->setText(QString());
        threshold_video_label->setText(QString());
        tracking_checkBox->setText(QApplication::translate("MainWindow", "tracking", Q_NULLPTR));
        quit_pushButton->setText(QApplication::translate("MainWindow", "quit", Q_NULLPTR));
        send_pushButton->setText(QApplication::translate("MainWindow", "send", Q_NULLPTR));
        done_pushButton->setText(QApplication::translate("MainWindow", "done", Q_NULLPTR));
        threshold_checkBox->setText(QApplication::translate("MainWindow", "threshold", Q_NULLPTR));
        Size_lbl->setText(QApplication::translate("MainWindow", "Size", Q_NULLPTR));
        Size_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        S_max_lbl->setText(QApplication::translate("MainWindow", "S_max", Q_NULLPTR));
        S_max_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        S_min_lbl->setText(QApplication::translate("MainWindow", "S_min", Q_NULLPTR));
        S_min_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        V_max_lbl->setText(QApplication::translate("MainWindow", "V_max", Q_NULLPTR));
        V_max_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        V_min_lbl->setText(QApplication::translate("MainWindow", "V_min", Q_NULLPTR));
        V_min_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        H2_threshold->setText(QString());
        H2_max_lbl->setText(QApplication::translate("MainWindow", "H_max", Q_NULLPTR));
        H2_max_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        H2_min_lbl->setText(QApplication::translate("MainWindow", "H_min ", Q_NULLPTR));
        H2_min_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        H2_enable_checkBox->setText(QApplication::translate("MainWindow", "H2", Q_NULLPTR));
        H3_threshold->setText(QString());
        H_max_lbl->setText(QApplication::translate("MainWindow", "H_max", Q_NULLPTR));
        H3_max_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        H3_min_lbl->setText(QApplication::translate("MainWindow", "H_min ", Q_NULLPTR));
        H3_min_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        H3_enable_checkBox->setText(QApplication::translate("MainWindow", "H3", Q_NULLPTR));
        H1_threshold->setText(QString());
        H1_max_lbl->setText(QApplication::translate("MainWindow", "H_max", Q_NULLPTR));
        H1_max_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        H1_min_lbl->setText(QApplication::translate("MainWindow", "H_min ", Q_NULLPTR));
        H1_min_value_lbl->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        H1_enable_checkBox->setText(QApplication::translate("MainWindow", "H1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
