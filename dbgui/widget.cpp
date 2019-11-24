#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/database.db");
    bool ok = db.open();

    //model = new QSqlQueryModel(this);
    //model -> setQuery("select id, firstname, lastname from People");
    model = new QSqlTableModel(this);
    model ->setTable("People");
    model -> select();
    model -> setHeaderData(0,Qt::Horizontal,"Identyfikator");

    ui -> tableView -> setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_update_clicked()
{
    model ->submitAll();
}
