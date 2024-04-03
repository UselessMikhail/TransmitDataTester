#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class LogWidget;
}

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = nullptr);

    void appendToLog(QString text);

    ~LogWidget();

private:
    Ui::LogWidget *ui;
};

#endif // LOGWIDGET_H
