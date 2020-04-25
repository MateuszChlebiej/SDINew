#include "image.h"

Image::Image(QObject *parent) : QObject(parent)
{
<<<<<<< Updated upstream

=======
    //set parameters
    image = imageData;
    fileName = filename;
    filePath = filename;
>>>>>>> Stashed changes
}

//set and get functions
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

