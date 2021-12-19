#include "projectwindow.h"
#include "ui_projectwindow.h"

ProjectWindow::ProjectWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectWindow)
{
    ui->setupUi(this);
}

ProjectWindow::~ProjectWindow()
{
    delete ui;
}
