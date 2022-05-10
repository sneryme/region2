#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    list = new QList<Region>;
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete model;
    delete list;
    delete ui;
}


void MainWindow::on_create_table_clicked()
{
    QString file_path;
    if (ui->line_file_pass->text()=="")
        file_path = QFileDialog::getOpenFileName(this,tr("Открыть файл"),"C://","all files(*.*);;text file(*.txt);;table file(*.csv)");
    else
        file_path = ui->line_file_pass->text();    
    QMessageBox::information(this,tr("информация"),file_path);
    rfile = new read_file(file_path.toStdString(), list);
    int check = rfile->Read_file();
    (check == -1) ? QMessageBox::critical(this, "информация","не удалось открыть файл"):QMessageBox::information(this, "информация","удалось открыть файл");
    model =new Model();
    model->populate(list);
    ui->tableView->setModel(model);
}

