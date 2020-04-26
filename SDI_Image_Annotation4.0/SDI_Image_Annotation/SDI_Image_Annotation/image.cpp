#include "image.h"

Image::Image(QImage image_data, QString file_name, QString file_path)
{
    //set parameters
    image = image_data;
    fileName = file_name;
    filePath = file_path;
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

