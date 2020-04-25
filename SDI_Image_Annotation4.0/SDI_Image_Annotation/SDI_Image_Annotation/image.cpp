#include "image.h"

Image::Image(QImage imageData, QString filename)
{
    //set parameters
    image = imageData;
    fileName = filename;
    filePath = filename;
}
Image::Image(){}

// set and get functions
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

