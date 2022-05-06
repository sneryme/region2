#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    list = new QList<Region>;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_create_table_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this,tr("Открыть файл"),"C://","all files(*.*);;text file(*.txt);;table file(*.csv)");
    QMessageBox::information(this,tr("информация"),file_path);
    rfile = new read_file(file_path.toStdString(), list);
    rfile->Read_file();
    model =new Model();
    model->populate(list);
    ui->tableView->setModel(model);
}

