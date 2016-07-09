#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->lineEditOG->setValidator( new QDoubleValidator(0, 10, 4, this) );
  ui->lineEditFG->setValidator( new QDoubleValidator(0, 10, 4, this) );

  ui->lineEditFG->setText("0.0");
  ui->lineEditOG->setText("0.0");
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  double OG = ui->lineEditOG->text().toDouble();
  double FG = ui->lineEditFG->text().toDouble();

  double ABV =(76.08 * (OG-FG) / (1.775-OG)) * (FG / 0.794);

  QString ABV_Representation = QString::number(ABV);

  ABV_Representation = "Alcohol volume%: " + ABV_Representation + " %";

  ui->label->setText(ABV_Representation);
}
