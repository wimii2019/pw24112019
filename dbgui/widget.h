#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_update_clicked();

private:
    Ui::Widget *ui;

    //QSqlQueryModel *model;
    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // WIDGET_H
