#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup> // Include the necessary header for QButtonGroup
#include <QLabel>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup* group1; // Declare these variables as member variables
    QButtonGroup* group2;
    QButtonGroup* group3;
    QButtonGroup* group4;
    QButtonGroup* group5;
};

#endif // MAINWINDOW_H
