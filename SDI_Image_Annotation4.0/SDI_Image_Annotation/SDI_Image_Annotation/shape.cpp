#include "shape.h"
#pragma once


<<<<<<< Updated upstream
Rectangle::Rectangle(QPoint *v1){
    QPainter painter;
    int x = int(v1->x());
    int y = int(v1->y());
    painter.drawRect(QRect(x,y,100,200));
}
=======
Shapes::Shapes(QString name, QPolygon poly){
    //set parameters
    className = name;
    shape = poly;
}

>>>>>>> Stashed changes
