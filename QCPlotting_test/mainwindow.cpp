#include "mainwindow.h"
#include "ui_mainwindow.h"
int a=1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // generate some data:
       QVector<double> x(101), y(101); // initialize with entries 0..100
       for (int i=0; i<101; ++i)
       {
         x[i] = i/50.0 - 1; // x goes from -1 to 1
         y[i] = x[i]*x[i]; // let's plot a quadratic function
       }
       // create graph and assign data to it:
       ui->widget->addGraph();
       ui->widget->graph(0)->setData(x, y);
       // give the axes some labels:
       ui->widget->xAxis->setLabel("x");
       ui->widget->yAxis->setLabel("y");
       // set axes ranges, so we see all data:
       ui->widget->xAxis->setRange(-1,1);
       ui->widget->yAxis->setRange(0, 1);
       ui->widget->replot();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    a=value;
}
