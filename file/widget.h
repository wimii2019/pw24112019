#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>

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
    void on_add_clicked();

    void on_remove_clicked();

private:
    Ui::Widget *ui;
    QFileSystemModel *model;
};

#endif // WIDGET_H
