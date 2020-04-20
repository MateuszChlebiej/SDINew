#include "image.h"

Image::Image(QObject *parent) : QObject(parent)
{

}


void Image::set_image_name(QString name){

    this->image_name = name;
}
void Image::set_image_path(QString path){

    this->image_path = path;
}

QString Image::get_image_name(){

    QString name = this->image_name;

    return name;
}

QString Image::get_image_path(){

    QString path = this->image_path;

    return path;
}

