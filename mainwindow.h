#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "devicesetting.h"
#include "contextmanager.h"
//#include "projectwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DeviceSetting *device_setting_ui = nullptr;
    ContextManager *ctx_manager=nullptr;

public slots:
    void openDeviceSettingWindow();
    void openProjectWindow();
};
#endif // MAINWINDOW_H
