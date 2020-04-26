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
#include <QJsonDocument>
#include <QMessageBox>
#include <QJsonObject>
#include <thread>
#include <chrono>
#include <QJsonArray>
#include "image.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shape.h"
#include "canvas.h"
#include "addclasswindow.h"
#include "list.h"
#include "autoSaveThread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //std::thread t1(autoSave);

    autoSave.start();
}

MainWindow::~MainWindow()
{

    autoSave.terminate();
    //autoSave.wait();
    delete ui;

}

//SELECTING IMAGE DIRECTORY
void MainWindow::on_btn_Select_Image_Folder_clicked()
{
    try {
          readImagesDirectory();
    } catch (...) {
        qDebug()<< "Failed to load in from images directory";
    }


}

//SELECTING AN IMAGE TO LOAD INTO CANVAS
void MainWindow::on_image_List_currentTextChanged(const QString &currentText)
{

    imageListCurrentTextChange(currentText);
}


//SELECTING FILE FOR CLASS FILES
void MainWindow::on_btn_Select_Class_File_clicked()
{

   MainWindow::readClassFile();
}


void MainWindow::on_dropdown_Sort_Image_activated(int index)
{
    sortImageNames(index);
}

void MainWindow::on_dropdown_Sort_Class_activated(int index)
{
    sortClassNames(index);
}

//may require seperate index for number of polygon verticies
void MainWindow::on_canvas_pressed(){

}

void MainWindow::on_rad_Btn_Rectangle_toggled(bool checked)
{

    ui->canvas->shapeIndex=0;


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


void MainWindow::on_btn_Save_Annotation_clicked()
{
    for(int i = 0 ; i < ui->canvas->imageList.size();i++){
        if(operator==(ui->canvas->currentImage.filePath,ui->canvas->imageList[i].filePath)){
            ui->canvas->imageList.replace(i,ui->canvas->currentImage);
        }
    }
   saveAnnotationFile("Manual Save");
}

void MainWindow::on_btn_Load_Annotation_clicked()
{
   readAnnotationFile();
}

void MainWindow::on_Rad_Btn_Edit_toggled(bool checked)
{
    ui->canvas->shapeIndex = 4;
}

void MainWindow::on_rad_Btn_Polygon_toggled(bool checked)
{
    ui->canvas->shapeIndex = 3;
}

void MainWindow::on_spinBox_Polygon_Sides_valueChanged(int arg1)
{
    ui->canvas->polyPoints = std::max(arg1,3);
    ui->canvas->polyPoints = std::min(arg1,9);

}

void MainWindow::on_rad_Btn_Move_Corner_toggled(bool checked)
{
    ui->canvas->shapeIndex = 5;
}

void MainWindow::on_rad_Btn_Copy_Paste_toggled(bool checked)
{
    ui->canvas->shapeIndex = 6;
}

void MainWindow::on_class_List_currentTextChanged(const QString &currentText)
{
    ui->canvas->setCurrentClass(currentText);
}
