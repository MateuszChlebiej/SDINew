#ifndef ADDCLASSWINDOW_H
#define ADDCLASSWINDOW_H

#include <QDialog>

namespace Ui {


class AddClassWindow;
}

class AddClassWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddClassWindow(QWidget *parent = nullptr);
    ~AddClassWindow();

signals:
    QString classEntered(QString);


private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddClassWindow *ui;
};

#endif // ADDCLASSWINDOW_H

