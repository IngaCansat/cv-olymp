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
    CHECKBOX_TRACKING = 0,
    CHECKBOX_THRESHOLD,
    CHECK_BOX_H1_ENABLE,
    CHECK_BOX_H2_ENABLE,
    CHECK_BOX_H3_ENABLE
} checkbox_name_t;

//std:: vector <double> map_distances;
/*std:: vector <Point> map_points { Point(1375, 925), Point(1325, 925), Point(1275, 925), Point(1225, 925),
    Point(1175, 925), Point(1125, 925), Point(1075, 925), Point(1025, 925), Point(975, 925), Point(925, 925), Point(875, 925),
    Point(825, 925), Point(775, 925), Point(725, 925), Point(675, 925), Point(625, 925), Point(575, 925), Point(525, 925),
    Point(475, 925), Point(425, 925), Point(375, 925), Point(325, 941), Point(286, 938), Point(250, 925), Point(219, 898),
    Point(197, 856), Point(185, 805), Point(184, 761), Point(185, 710), Point(184, 660), Point(184, 606), Point(182, 560),
    Point(182, 503), Point(182, 454), Point(182, 403), Point(182, 352), Point(179, 296), Point(177, 236), Point(185, 187),
    Point(215, 158), Point(261, 148), Point(303, 147), Point(347, 145), Point(386, 147), Point(429, 147), Point(475, 147),
    Point(530, 147), Point(586, 148), Point(644, 146), Point(695, 146), Point(744, 147), Point(790, 154), Point(824, 179),
    Point(843, 214), Point(844, 251), Point(830, 290), Point(808, 320), Point(781, 347), Point(754, 381), Point(723, 415),
    Point(698, 453), Point(678, 497), Point(705, 681), Point(745, 716), Point(795, 740), Point(840, 746), Point(888, 738),
    Point(933, 719), Point(972, 686), Point(1006, 650), Point(1032, 605), Point(1058, 556), Point(1077, 504), Point(1105, 462),
    Point(1143, 437), Point(1192, 425), Point(1244, 417), Point(1288, 401), Point(1322, 368), Point(1335, 322), Point(1334, 268),
    Point(1343, 215), Point(1358, 179), Point(1398, 152), Point(1438, 146), Point(1479, 150), Point(1532, 143), Point(1580, 145),
    Point(1618, 150), Point(1662, 166), Point(1695, 188), Point(1725, 222), Point(1746, 258), Point(1758, 318), Point(1755, 377),
    Point(1741, 430), Point(1727, 476), Point(1721, 530), Point(1723, 584), Point(1735, 630), Point(1748, 677), Point(1762, 727),
    Point(1764, 780), Point(1752, 832), Point(1729, 874), Point(1690, 904), Point(1650, 919), Point(1604, 923), Point(1561, 923),
    Point(1501, 923), Point(1443, 924) };*/

/*Point find_line_coordinates (Robot robot) {
    Point closest1, closest2;
    double min_dist = 5000;
    int i_of_min;
    double min_dist2 = 5000;
    for (int i = 0; i < 111; i++) {
        double dist = getDistance(robot.curr_coordinates, map_points[i]);
        if (dist < min_dist) {
            min_dist = dist;
            closest1 = map_points[i];
            i_of_min = i;
        }
        if (dist < min_dist2 && i != i_of_min) {
            min_dist2 = dist;
            closest2 = map_points[i];
        }
    }
    return findCenter(closest1, closest2);
}*/

/*double getMapDistance(Robot robot1, Robot robot2) { // между двумя роботами
    Point line1 = robot1.curr_line_coordinates;
    Point line2 = robot2.curr_line_coordinates;
    int pos1 = std::find(map_points.begin(), map_points.end(), line1) - map_points.begin();
    int pos2 = std::find(map_points.begin(), map_points.end(), line2) - map_points.begin();
    double D = 0.0;
    for (int i = pos1; i < pos2; i++) {
        D += map_distances[i];
    }
    return D;
}
void fillMapDistances() {
    for (size_t i = 0; i < map_points.size() - 1; i++) {
        map_distances.emplace_back(getDistance(map_points[i], map_points[i+1]));
    }
}
void fillDistBetween(Robot robot) {
    for (size_t i = 0; i < objects.size(); i++) {
        robot.distBetween[i] = getMapDistance(robot, objects[i]);
    }
}*/

#endif // HEADER_H
