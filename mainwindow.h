#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#define LOG logWidget->appendToLog

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QSettings>

#include "Tools/logwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    // FileMenu
    void openConfigFile();
    // ToolsMenu
    void showLogWidget();

private slots:


private:
    Ui::MainWindow *ui;
    LogWidget* logWidget = nullptr;

    // Реестр
    void readSettings();
    void writeSettings();

    void loadUIfromCfgFile(QString fileName);



};
#endif // MAINWINDOW_H
