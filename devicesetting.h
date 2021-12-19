#ifndef DEVICESETTING_H
#define DEVICESETTING_H

#include <QDialog>
#include <QPushButton>
#include <vulkan/vulkan.h>
#include <QListWidgetItem>
#include "contextmanager.h"

namespace Ui {
class DeviceSetting;
}



class DeviceSetting : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceSetting(QWidget *parent = nullptr);
    ~DeviceSetting();

private:
    Ui::DeviceSetting *ui;


public slots :
    void onSearchBtnClicked();
    void onItemSelected();
    void onCancelBtnClicked();
};

#endif // DEVICESETTING_H
