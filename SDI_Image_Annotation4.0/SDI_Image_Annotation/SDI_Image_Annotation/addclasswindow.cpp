#include "addclasswindow.h"
#include "mainwindow.h"
#include "ui_addclasswindow.h"
#include "ui_mainwindow.h"
#include <QFile>

AddClassWindow::AddClassWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClassWindow)
{
    ui->setupUi(this);
}

AddClassWindow::~AddClassWindow()
{
    delete ui;
}

void AddClassWindow::on_buttonBox_accepted()
{

   emit classEntered(ui->newClassEntry->text());

}
