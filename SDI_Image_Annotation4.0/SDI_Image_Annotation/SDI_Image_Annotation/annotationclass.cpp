#include "annotationclass.h"

AnnotationClass::AnnotationClass(QObject *parent) : QObject(parent)
{

}


void AnnotationClass::set_name_and_line(QString class_name, int line_number){

    this->class_line_number = line_number;
    this->class_name = class_name;

}


QString  AnnotationClass::get_name(){

    QString name = this->class_name;

    return  name;
}

int AnnotationClass::get_line_number(){
    int line_number = this->class_line_number;

    return line_number;
}

