#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QmessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/claude/Documents/QT/CircularMotionClaudeSukmana/diagramF.png");
    ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //The values that are taken for calculation
    accel = ui->accel->value();
    radius = ui->radius->value();
    time = ui->time->value();
    wi = ui->wi->value();

    double wf = (wi+(accel)*(time*time));
    ui->textBrowser->setText("The final angular velocity (rad/s):");
    ui->textBrowser->append(QString::number(wf));

    double angulardisplacement = ((wi*time)+(0.5*accel)*(time*time));
    ui->textBrowser->append("The angular displacement (pi radians)");
    ui->textBrowser->append(QString::number(angulardisplacement));

    double linearvelocity = (wf*radius);
    ui->textBrowser->append("The final linear velocity after time elapsed (m/s) :");
    ui->textBrowser->append(QString::number(linearvelocity));

    double lineardistance = (angulardisplacement*radius);
    ui->textBrowser->append("The circular distance after time elapsed (m):");
    ui->textBrowser->append(QString::number(lineardistance));
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText("Hi, Welcome This code is a calculator for circular motion with constant acceleration condition. By inputing angular acceleration, initial angular velocity, radius, and time elapsed you can find the angular displacement, final angular velocity, distance traveled along the circular path, and final velocity.");
    msgBox.exec();

}

