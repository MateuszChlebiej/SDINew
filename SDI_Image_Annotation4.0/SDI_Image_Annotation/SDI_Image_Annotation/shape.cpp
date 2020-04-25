#include "shape.h"
#pragma once


Shapes::Shapes(QString name, QPolygon poly){
    //set parameters
    className = name;
    shape = poly;
}


