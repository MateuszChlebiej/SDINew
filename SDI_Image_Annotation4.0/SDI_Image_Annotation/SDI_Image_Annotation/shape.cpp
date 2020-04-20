#include "shape.h"
#pragma once
//Shape::Shape(){};

//void Shape::drawRect(){
//    QPainter painter;
//    painter.drawRect(QRect(80,120,200,100));



//}

Rectangle::Rectangle(QPoint *v1){
    QPainter painter;
    int x = int(v1->x());
    int y = int(v1->y());
    painter.drawRect(QRect(x,y,100,200));
}
