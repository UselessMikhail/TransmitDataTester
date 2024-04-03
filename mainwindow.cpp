#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Transmit data tester v1.0");

    connect(ui->actionOpenFile,SIGNAL(triggered()),this,SLOT(openConfigFile()));

    logWidget = new LogWidget(nullptr);
    connect(ui->actionShowLogs,SIGNAL(triggered()),this,SLOT(showLogWidget()));
    showLogWidget();

    ui->labelCurrentCfgFileName->setText("Файл конфигурации не открыт...");
    ui->statusbar->addPermanentWidget(ui->labelCurrentCfgFileName,1);

    readSettings();

}

MainWindow::~MainWindow()
{
    qDebug()<<"~MainWindow()";
    delete logWidget;
    delete ui;
}

void MainWindow::openConfigFile()
{
    LOG("Open file...");

    QString cfgFileName;
    cfgFileName = QFileDialog::getOpenFileName(this,
                                               tr("Открыть файл конфигурации..."), "",
                                               tr("All files (*.*);;"));

    if (!cfgFileName.isNull())
    {
        LOG("Имя файла конфигурации = " + cfgFileName);
        loadUIfromCfgFile(cfgFileName);
    }
    else
    {
        LOG("Пустое имя файла конфигурации!");
    }

}

void MainWindow::showLogWidget()
{
    logWidget->show();
}

void MainWindow::readSettings()
{
    QSettings settings("OCEANOS","TransmitDataTester");
    loadUIfromCfgFile(settings.value("filePath").toString());

}

void MainWindow::writeSettings()
{

}

void MainWindow::loadUIfromCfgFile(QString fileName)
{
    LOG("Загрузка конфигурации из файла= " + fileName);

    if(fileName.isEmpty())
    {
        LOG("Пустое имя файла конфигурации loadUIfromCfgFile!");
        ui->labelCurrentCfgFileName->setText("Файл конфигурации не открыт!...");
    }
    else
    {
        QSettings settings("OCEANOS","TransmitDataTester");
        settings.setValue("filePath",fileName);

        QStringList filePath = fileName.split("/");
        ui->labelCurrentCfgFileName->setText("Открыт файл конфигурации = " + filePath.last());
    }
}




