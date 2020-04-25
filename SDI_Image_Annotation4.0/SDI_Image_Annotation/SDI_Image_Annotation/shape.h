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



    /*!
     * \brief vertex 1
     *first vertex of shape
     */
    QVector2D vertex1;
};


