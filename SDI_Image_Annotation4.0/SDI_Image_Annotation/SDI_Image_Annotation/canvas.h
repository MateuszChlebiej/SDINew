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
    /*!
        * \brief Canvas constructor
        * calls constructor
        * \param parent widget
        */
    Canvas(QWidget *parent = nullptr);
    /*!
        * \brief pixmap
        * pixmap of canvas
        */
    QPixmap pixmap;
    /*!
         * \brief lastMousePosition
         *position of mouse on last click
         */
    QPoint lastMousePos = QPoint(0,0);
    /*!
         * \brief currentMousePosition
         * current position of mouse on canvas
         */
    QPoint currentMousePos = QPoint(0,0);


    /*!
         * \brief trapeziumDistanceConstant
         *constant to alter the distance between the top points of the trapezium and the bottom points
         */
    const int trapeziumDistanceConstant = 30;
    /*!
      * \brief trapDist
      *used in defining the distance between points in a trapezium
      */
    int trapDist;
    /*!
       * \brief drawing
       * if the canvas is drawing a shape
       */
    bool drawing = false;
    /*!
     * \brief moving
     * if the canvas is moving a shape
     */
    bool moving = false;
    /*!
     * \brief hovering
     * if mouse is hovered over a shape
     */
    bool hovering = true;
    /*!
     * \brief point index
     * used to points in polygon drawing
     */
    int pointIndex = 0;
    /*!
         * \brief polygon points
         *  number of points new custom polygons have
         *
         */
    int polyPoints = 3;
    /*!
      * \brief point selection tolerance
      *offset of pixels the mouse can be within a corner to sleect a corner
      */
    const int pointSelectionTolerance = 10;
    /*!
      * \brief move index
      *used to track which shape in the list is being moved
      */
    int moveIndex;
    /*!
      * \brief point move index
      *used to track which point in a shape is being moved
      */
    int pointMoveIndex;
    /*!
      * \brief point list
      *list of x and y coordinates used in making custom polygons
      */
    int* pointList;
    /*!
      * \brief current image
      * image that is currently being worked on
      */
    Image currentImage;
    /*!
      * \brief image list
      * list of all images that the canvas has loaded
      */
    QList<Image> imageList;
    /*!
      * \brief clipboard polygon
      * polygon that has been copied and will be duplicated when pasted
      */
    QPolygon clipboardPolygon;
    /*!
      * \brief current point
      *the point that is currently selected, used for moving the point.
      */
    QPoint currentPoint;
    /*!
      * \brief shape index
      * defines the current mode for image manipulation, 100 by default so no mode is active on launch
      * 0 = draw rect, 1 = draw trapezium, 2 = draw triangle, 3 = draw custom polygon, 4 = move or delete shape, 5 = move points, 6 = copy or paste shape
      */
    int shapeIndex = 100;

    /*!
      * \brief setCurrentClass
      * sets the class that new shapes will be associated with
      * \param the new class
      */
    void setCurrentClass(QString newClass);
protected:

    /*!
      * \brief mousePressEvent
      * called when mouse is pressed on canvas
      * \param mouse event data
      */
    void mousePressEvent(QMouseEvent *ev) override;
    /*!
     * \brief mouseMoveEvent
     * called when mouse is moved around the canvas
     * \param mouse event data
     */

    void mouseMoveEvent(QMouseEvent *ev) override;

    /*!
     * \brief mouseReleaseEvent
     * called when mouse button is released on canvas
     * \param mouse event data
     */
    void mouseReleaseEvent(QMouseEvent *ev) override;
    /*!
      * \brief paintEvent
      * responsible for rendering everything on the canvas, called with update()
      * \param paint event data
      */
    void paintEvent(QPaintEvent *ev) override;



private:
    /*!
      * \brief currentClass
      * Class to associate new shapes too
      */
    QString currentClass;

};
