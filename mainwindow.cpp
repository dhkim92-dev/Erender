#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ContextManager::getInstance();
//    int gpu_id = ctx_manager->getGPUId();
    ui->setupUi(this);
    connect(ui->actionDevice_Setting, &QAction::triggered, this, &MainWindow::openDeviceSettingWindow);
    connect(ui->newProjectBtn, &QPushButton::clicked, this, &MainWindow::openProjectWindow );
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openDeviceSettingWindow(){
    if(!device_setting_ui){
        device_setting_ui = new DeviceSetting();
    }
//    device_setting_ui->setModal(true);
//    device_setting_ui->exec();
    device_setting_ui->show();
}

void MainWindow::openProjectWindow(){
    //ProjectWindow *prj_window = new ProjectWindow();
    //prj_window->show();
}
