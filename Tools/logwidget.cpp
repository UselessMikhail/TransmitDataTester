#include "logwidget.h"
#include "ui_logwidget.h"

LogWidget::LogWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWidget)
{
    ui->setupUi(this);

    this->hide();
    this->setWindowTitle("Log");
}

void LogWidget::appendToLog(QString text)
{
    ui->plainTextLog->insertPlainText(text+"\r\n");
}


LogWidget::~LogWidget()
{
    qDebug()<<"~LogWidget()";
    delete ui;
}
