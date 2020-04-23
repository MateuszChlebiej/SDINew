#ifndef CANVAS_H
#define CANVAS_H

#endif // CANVAS_H
#include<QLabel>
#include<QMouseEvent>
#include<QDebug>
#include "shape.h"
#include "image.h"
#pragma once
class Canvas: public QLabel{
    Q_OBJECT

public:
//    Canvas(QLabel *parent = nullptr);
    Canvas(QWidget *parent = nullptr);
    QPixmap pixmap;
    QPoint lastMousePos = QPoint(0,0);
    QPoint currentMousePos = QPoint(0,0);



    const int trapeziumDistanceConstant = 30;
    int trapDist;
    bool drawing = false;
    int pointIndex = 0;
    int polyPoints = 3;
    int* pointList;
    Image currentImage;
    QList<Image> imageList;
    int shapeIndex = 100;
protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void paintEvent(QPaintEvent *ev) override;
    void paintPolygon(QPolygon polygon);


private:

};
