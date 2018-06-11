#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "root.h"
#include "image.h"
#include <QMessageBox>

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

void MainWindow::on_btn_checkfile_clicked()
{
    QString filename1 = ui -> line_input -> text();


    Image image = Image("/home/max/Desktop/FileSystemEditor/hd0.img");
    Root root = Root(image);

    std::string filename = filename1.toStdString();

    auto res = root.find_file(filename);

    if (res == -1){
        QMessageBox msgbx;
        msgbx.setText("File not found");
        msgbx.exec();
    } else {
        auto file = root.getFile(res);
        ui -> line_filename -> setText(QString::fromStdString(file.filename));
        ui -> line_filesize -> setText(QString::number(file.file_size));
        ui -> line_modifydate -> setText(QString::number(file.modify_date));
        ui -> line_creationdate -> setText(QString::number(file.time_created));
        ui -> line_attributes -> setText(QString::number(file.attributes));
        ui -> line_cluster-> setText(QString::number(file.starting_cluster));
    }
}

void MainWindow::on_pushButton_clicked()
{
    Image image = Image("/home/max/Desktop/FileSystemEditor/hd0.img");
    Root root = Root(image);

    auto qwe = root.getFile(0);
    QString qfilename = ui -> line_filename -> text();
    std::string fn = qfilename.toStdString();
    strcpy(qwe.filename, fn.c_str());
    image.edit(qwe);
}
