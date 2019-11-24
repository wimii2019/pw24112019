#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);
    model->setRootPath("/tmp");
    model->setReadOnly(false);

    ui->treeView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_add_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid())
        return;
    QString name = "Katalog";
    model->mkdir(index,name);
}



void Widget::on_remove_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(model->fileInfo(index).isDir()){
        model->rmdir(index);
    }
    else{
        model->remove(index);
    }
}
