#include "devicesetting.h"
#include "ui_devicesetting.h"
#include <iostream>
#include <string>
DeviceSetting::DeviceSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceSetting)
{
    ui->setupUi(this);
    connect(ui->searchBtn, &QPushButton::clicked, this, &DeviceSetting::onSearchBtnClicked);
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &DeviceSetting::onItemSelected);
}

DeviceSetting::~DeviceSetting()
{
    delete ui;
}

void DeviceSetting::onSearchBtnClicked(){
    std::cout << "search btn clicked" << std::endl;
    ContextManager::getInstance()->searchDevice();
    uint32_t nr_gpus = 0;
    VkPhysicalDeviceProperties *properties = ContextManager::getInstance()->getGPUProperties(&nr_gpus);

    if(nr_gpus==0)
        return;

    ui->listWidget->clear();
    for(uint32_t i = 0 ; i < nr_gpus ; i++){
        ui->listWidget->addItem(QString(properties[i].deviceName));
    }
}

void DeviceSetting::onItemSelected(){
    for(auto item : ui->listWidget->selectedItems()){
        string name = item->text().toStdString();
        int idx = ui->listWidget->indexFromItem(item).row();
        std::cout << name << std::endl;
        std::cout << "gpu id : " << idx << std::endl;
        ContextManager::getInstance()->setGPUId(idx);
        ui->listWidget->window()->close();
    }
}


void DeviceSetting::onCancelBtnClicked(){
    ui->listWidget->window()->close();
}

