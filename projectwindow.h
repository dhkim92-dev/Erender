#ifndef PROJECTWINDOW_H
#define PROJECTWINDOW_H

#include <QWidget>
#include <QVulkanWindow>
#include <QVulkanWindowRenderer>


namespace Ui {
class ProjectWindow;
}

class ProjectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectWindow(QWidget *parent = nullptr);
    ~ProjectWindow();

private:
    Ui::ProjectWindow *ui;
};

#endif // PROJECTWINDOW_H
