#ifndef SHAPE_H
#define SHAPE_H

#endif // SHAPE_H

#include <QMainWindow>
#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <QtQuick/QQuickItem>
#include <QVector2D>
#pragma once
class Shape {
    //Q_OBJECT

public:
    //virtual void drawRect(QPaintEvent *event);

private:
    int shapeID;

    QVector2D vertex1;
};

class Triangle : Shape {

};

class Rectangle : Shape {
public:
    Rectangle(QPoint *v1);
};

class Trapezium : Shape {

};

class Polygon : Shape {

};
