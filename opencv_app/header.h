#ifndef HEADER_H
#define HEADER_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

using namespace cv;

typedef enum {
    LABEL_NOFILTER = 0,
    LABEL_THRESHOLD,

    LABEL_H1_THRESHOLD,
    LABEL_H2_THRESHOLD,
    LABEL_H3_THRESHOLD,

    LABEL_H1_MAX_VALUE,
    LABEL_H1_MIN_VALUE,

    LABEL_H2_MAX_VALUE,
    LABEL_H2_MIN_VALUE,

    LABEL_H3_MAX_VALUE,
    LABEL_H3_MIN_VALUE,

    LABEL_S_MAX_VALUE,
    LABEL_S_MIN_VALUE,
    LABEL_V_MAX_VALUE,
    LABEL_V_MIN_VALUE
} lbl_name_t;

typedef enum {
    SLIDER_H1_MAX = 0,
    SLIDER_H1_MIN,

    SLIDER_H2_MAX,
    SLIDER_H2_MIN,

    SLIDER_H3_MAX,
    SLIDER_H3_MIN,

    SLIDER_S_MAX,
    SLIDER_S_MIN,

    SLIDER_V_MAX,
    SLIDER_V_MIN
} slider_name_t;

typedef enum {
    RED = 0,
    GREEN,
    BLUE
} color_t;

typedef enum {
    CHECKBOX_TRACKING = 0,
    CHECKBOX_THRESHOLD,
    CHECK_BOX_H1_ENABLE,
    CHECK_BOX_H2_ENABLE,
    CHECK_BOX_H3_ENABLE
} checkbox_name_t;

#endif // HEADER_H
