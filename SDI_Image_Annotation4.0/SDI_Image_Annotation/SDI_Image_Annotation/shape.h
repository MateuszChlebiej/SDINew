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
<<<<<<< Updated upstream
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
=======

    /*!
     * \brief shape
     *the polygon that represents the shape
     */
    QPolygon shape;
    /*!
     * \brief shape name
     * name of shape
     */
    QString shapeName;
    /*!
     * \brief class name
     * class associated with the shape
     */
    QString className;

    Shapes() {};
    /*!
     * \brief shapes
     *overloaded constructor to define shape parameters
     * \param class name, polygon
     */
    Shapes(QString name,QPolygon poly);


private:

>>>>>>> Stashed changes

    /*!
     * \brief vertex 1
     *first vertex of shape
     */
    QVector2D vertex1;
};

<<<<<<< Updated upstream
class Polygon : Shape {

};
=======
>>>>>>> Stashed changes
