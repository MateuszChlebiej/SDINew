#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDirIterator>
#include <QDateTime>
#include <qdebug.h>
#include <QVector2D>
#include <QCursor>
#include <algorithm>
#include "image.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shape.h"
#include "canvas.h"
#include "addclasswindow.h"
#include "list.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{

    delete ui;

}

//SELECTING IMAGE DIRECTORY
void MainWindow::on_btn_Select_Image_Folder_clicked()
{
    readImagesDirectory();
}

//SELECTING AN IMAGE TO LOAD INTO CANVAS
void MainWindow::on_image_List_currentTextChanged(const QString &currentText)
{
    if(currentText == ""){
        qDebug() << "NoItem";
    }
    else{
        qDebug()<< "ImageList" << currentText;
        //Find the image path by looking at Vector with image name and full path.
        QString file_path = images_list.FindNodeGivePath(currentText);
        //Send corresponding image to canvas.
        QImage image(file_path);
        ui->canvas->setPixmap(QPixmap::fromImage(image));
        //set canvas image to current image
    ui->canvas->image = image;
    }
}

//SELECTING FILE FOR CLASS FILES
void MainWindow::on_btn_Select_Class_File_clicked()
{

   MainWindow::readClassFile();

}


void MainWindow::on_dropdown_Sort_Image_activated(int index)
{
    QStringList sorted_images;
    switch(index){


        case 0:
            ui->image_List->clear();
            sorted_images = sortingName(images_list.name_List, ">");
            ui->image_List->addItems(sorted_images);

        break;

        case 1:
            ui->image_List->clear();
            sorted_images = sortingName(images_list.name_List, "<");
            ui->image_List->addItems(sorted_images);

        break;

        case 2:
            ui->image_List->clear();
            sorted_images = images_list.GetModifiedList("Ascending");
            ui->image_List->addItems(sorted_images);
        break;

        case 3:
            ui->image_List->clear();
            sorted_images = images_list.GetModifiedList("Descending");
            ui->image_List->addItems(sorted_images);
        break;
    }
}

void MainWindow::on_dropdown_Sort_Class_activated(int index)
{
    QStringList sorted_classes;
    switch(index){
        case 0:

           ui->class_List->clear();
           qDebug()<<classes_list.name_List;
           sorted_classes = sortingName(classes_list.name_List,">");
           qDebug()<<sorted_classes;
           ui->class_List->addItems(sorted_classes);

        break;

        case 1:

            ui->class_List->clear();
            sorted_classes = sortingName(classes_list.name_List,"<");

            qDebug()<<sorted_classes;
            ui->class_List->addItems(sorted_classes);
            qDebug()<<classes_list.name_List;

        break;
    }
}

//may require seperate index for number of polygon verticies
void MainWindow::on_canvas_pressed(){
//    QPoint mouse = QCursor::pos();
//    QVector2D mousePos;
//    mousePos.setX(mouse.x());
//    mousePos.setY((mouse.y()));

//    if(canvas.shapeIndex == 0){
//        //Rectangle * rect = new Rectangle(&mousePos);
//    }
//    else if (canvas.shapeIndex == 1){

//    }
}

void MainWindow::on_rad_Btn_Rectangle_toggled(bool checked)
{
    //shapeIndex = 0;
    ui->canvas->shapeIndex=0;
    qDebug() << "checked";
}

void MainWindow::on_rad_Btn_Trapezium_toggled(bool checked)
{
    ui->canvas->shapeIndex = 1;
}

void MainWindow::on_rad_Btn_Triangle_toggled(bool checked)
{
    ui->canvas->shapeIndex = 2;
}

void MainWindow::on_btn_Add_Class_clicked()
{

    addclasswindow = new AddClassWindow();

    QObject::connect(addclasswindow, SIGNAL(classEntered(QString)), this, SLOT(update_class_list_and_file_add(QString)));
    addclasswindow->show();
}

void MainWindow::on_btn_Delete_Class_clicked()
{
    if(ui->class_List->selectedItems().size() != 0){
        QString classSelected = ui->class_List->currentItem()->text();
        update_class_list_and_file_delete(classSelected);
    }
    else{
         QMessageBox::warning(this,"No Selection","Please select which class you want to delete.");
    }
}

void MainWindow::on_rad_Btn_Polygon_clicked(bool checked)
{
    ui->canvas->shapeIndex = 3;
}

void MainWindow::on_spinBox_Polygon_Sides_valueChanged(int arg1)
{
    ui->canvas->polyPoints = std::max(arg1,3);
}

void MainWindow::makeAnnotationFile(){
    QString fileContents = "";
    //num annotated images
    //for each image
    //file name
    // num shapes
    int numShapes = ui->canvas->polygonList.size();
    fileContents.append(QString::number(numShapes) + ",\n");
    //for each shape:
    for(QPolygon polygon: ui->canvas->polygonList){
        //num vertecies:
        int numVerticies = ui->canvas->polygonList.size();

        fileContents.append(QString::number(numVerticies) + ",\n");
        QList<QPoint> pointList = ui->canvas->getPoints(numVerticies,ui->canvas->polygonList.indexOf(polygon));
        //each vertex
        for(QPoint point: pointList){
            fileContents.append(QString::number(point.x()) + "," + QString::number(point.y()) + ",\n");
        }

    }
    //save string to file

}
