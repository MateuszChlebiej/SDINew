#ifndef SHAPE_H
#define SHAPE_H

#endif // SHAPE_H

#include <QMainWindow>
#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <QtQuick/QQuickItem>
#include <QVector2D>
#pragma once
class Shapes {
    //Q_OBJECT

public:
    //virtual void drawRect(QPaintEvent *event);
    QPolygon shape;
    QString shapeName;
    QString className;
    Shapes() {};
    Shapes(QString name,QPolygon poly);


private:
    int shapeID;

    QVector2D vertex1;
};

class Triangle : Shapes {

};

class Rectangle : Shapes {
public:
    Rectangle(QPoint *v1);
};

class Trapezium : Shapes {

};

class Polygon : Shapes {

};
