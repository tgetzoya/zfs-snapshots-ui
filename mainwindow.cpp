#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    showQuitConfirmationDialogBox();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    /* Ignore the button press. The Dialog will have authority. */
    event->ignore();
    showQuitConfirmationDialogBox();
}

void MainWindow::showQuitConfirmationDialogBox()
{
    switch(QMessageBox::question(
                this,
                tr("ZFS Snapshots GUI"),
                tr("Are you sure you want to exit the application?"),
                QMessageBox::Yes,
                QMessageBox::Cancel ) )
    {
      case QMessageBox::Yes:
        qDebug("Quitting application.");
        QApplication::quit();
        break;
      case QMessageBox::Cancel:
      default:
        qDebug("Quit cancelled.");
    }
}
