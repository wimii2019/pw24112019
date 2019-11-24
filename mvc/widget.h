#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    QStringListModel *model;

private slots:
    void on_addButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
