#include <QApplication>
#include <QVulkanInstance>

#include "mainwindow.h"
#include "devicesetting.h"
#include "contextmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ContextManager::getInstance();
    w.show();

    return a.exec();
}
