#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStringListModel(this);

    QStringList list;
    list << "Audi" << "BMW" <<"VW";
    model->setStringList(list);

    ui->comboBox->setModel(model);
    ui->listView->setModel(model);
}



void Widget::on_addButton_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->insertRow(index.row());
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void Widget::on_removeButton_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow(index.row());
}
