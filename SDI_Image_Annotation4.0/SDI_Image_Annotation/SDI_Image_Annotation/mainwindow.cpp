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
    int lineNum = 0;
    List list;

    QStringList arr_image_names;
    QString folder_name = QFileDialog::getExistingDirectory(this, ("Select Output Folder"),"C:/Users/mateu/Desktop");
    QDir dir_2(folder_name);

    //Look at each file within directory
    foreach(QFileInfo var, dir_2.entryInfoList()){
        //If file suffix == jpg or png
        if ((var.suffix() == "jpg") || (var.suffix() == "png")){
            //Store image data in Vectors
            image_data.append(var.filePath());
            image_data.append(var.baseName());

            //Pass image name into UI to be displayed
            ui->image_List->addItem(var.baseName());
            //Add to list with image names used for sorting.
            images_list << var.baseName();


            list.InsertNode(lineNum,var.baseName(),var.filePath());


        }
   }

    list.DisplayList();


    //Change gui label showing path of current directory.
    ui->folder_Path_Image->setText(folder_name);
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
        int file_path_index = image_data.indexOf(currentText)-1;
        QString filename = image_data[file_path_index];
        //Send corresponding image to canvas.
        QImage image(filename);
        ui->canvas->setPixmap(QPixmap::fromImage(image));
        //set canvas image to current image
    ui->canvas->image = image;
    }
}

//SELECTING FILE FOR CLASS FILES
void MainWindow::on_btn_Select_Class_File_clicked()
{

   MainWindow::readClassFile("New");
}


void MainWindow::on_dropdown_Sort_Image_activated(int index)
{
    QStringList sorted_images;
    switch(index){


        case 0:


        break;

        case 1:

        break;

        case 2:
            ui->image_List->clear();
            sorted_images = sorting_images(images_list, ">");
            ui->image_List->addItems(sorted_images);
        break;

        case 3:
            ui->image_List->clear();
            sorted_images = sorting_images(images_list, "<");
            ui->image_List->addItems(sorted_images);
        break;
    }
}

void MainWindow::on_dropdown_Sort_Class_activated(int index)
{
    switch(index){
        case 0:
            ui->class_List->clear();
            int size;
            size= classes_list.count();
            for(int i = 0; i< size; i++){
                for(int j=0; j<size-1; j++){
                    if(classes_list[j]>classes_list[j+1]){
                        QString tmp;
                        tmp = classes_list[j];
                        classes_list[j] = classes_list[j+1];
                        classes_list[j+1] = tmp;
                    }
                }
            }
            ui->class_List->addItems(classes_list);

        break;

        case 1:
        ui->class_List->clear();
        size= classes_list.count();
        for(int i = 0; i< size; i++){
            for(int j=0; j<size-1; j++){
                if(classes_list[j]<classes_list[j+1]){
                    QString tmp;
                    tmp = classes_list[j];
                    classes_list[j] = classes_list[j+1];
                    classes_list[j+1] = tmp;
                }
            }
        }
        ui->class_List->addItems(classes_list);
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

    QObject::connect(addclasswindow, SIGNAL(classEntered(QString)), this, SLOT(update_class_list_and_file(QString)));
    addclasswindow->show();
}

void MainWindow::on_btn_Delete_Class_clicked()
{
    if(ui->class_List->selectedItems().size() != 0){
        QString classSelected = ui->class_List->currentItem()->text();
        QFile f(MainWindow::classFile);
        if(f.open(QIODevice::ReadWrite | QIODevice::Text)){
            QString s;
            QTextStream t(&f);
            while(!t.atEnd())
            {
                QString line = t.readLine();
                if(!line.contains(classSelected))
                    s.append(line + "\n");
            }
            f.resize(0);
            t << s;
            f.close();
        }
        MainWindow::readClassFile("Update");

    }
    else{
         QMessageBox::warning(this,"No Selection","Please select which class you want to delete.");
    }
}

void MainWindow::on_btn_Save_Annotation_clicked()
{
    QString json_filter = "JSON (*.json)";
    QString file = QFileDialog::getSaveFileName(this,tr("Save File"),"/",json_filter);

    if(file.isEmpty()){

    }
    else{
        QString value1 = "Tom";
        QString value2 = "Jim";
        QString value3 = "Mat";
        QString value4 = "Bob";

        QJsonDocument doc;
        QJsonObject obj;
        obj["Value1"] = value1;
        obj["Value2"] = value2;
        obj["Value3"] = value3;
        obj["Value4"] = value4;

        doc.setObject(obj);
        QByteArray data_json = doc.toJson();
        QFile output(file);
        if(output.open(QIODevice::WriteOnly | QIODevice::Text)){
            output.write(data_json);
            output.close();
            QMessageBox::information(this,tr("Message"),tr("Document saved"));
        }
        else{
            QMessageBox::critical(this,tr("Error"),output.errorString());
        }

    }

}

void MainWindow::on_btn_Load_Annotation_clicked()
{
    QString json_filter = "JSON (*.json)";
    QString file = QFileDialog::getOpenFileName(this,tr("Open File"),"/",json_filter);

    if(file.isEmpty()){
    }
    else{
        QJsonDocument doc;
        QJsonObject obj;
        QByteArray data_json;
        QFile input(file);
        if(input.open(QIODevice::ReadOnly | QIODevice::Text)){
            data_json = input.readAll();
            doc = doc.fromJson(data_json);
            obj = doc.object();

            QString value1 = obj["Value1"].toString();
            qDebug()<<value1;
            QString value2 = obj["Value2"].toString();
             qDebug()<<value2;
            QString value3 = obj["Value3"].toString();
             qDebug()<<value3;
            QString value4 = obj["Value4"].toString();
             qDebug()<<value4;

            QMessageBox::information(this,tr("Message"),tr("Document Open"));
        }
        else{
             QMessageBox::critical(this,tr("Error"),input.errorString());
        }
    }
}
