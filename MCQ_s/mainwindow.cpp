#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QLabel>
#include <QMap>
#include <QMessageBox>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up QButtonGroups for radio buttons of each question
    std::unique_ptr<QButtonGroup> group1 = std::make_unique<QButtonGroup>(this);
    group1->addButton(ui->r1);
    group1->addButton(ui->r2);
    group1->addButton(ui->r3);
    group1->addButton(ui->r4);

    // Repeat the same pattern for each set of radio buttons (questions)
    std::unique_ptr<QButtonGroup> group2 = std::make_unique<QButtonGroup>(this);
    group2->addButton(ui->r1_2);
    group2->addButton(ui->r2_2);
    group2->addButton(ui->r3_2);
    group2->addButton(ui->r4_2);

    std::unique_ptr<QButtonGroup> group3 = std::make_unique<QButtonGroup>(this);
    group3->addButton(ui->r1_4);
    group3->addButton(ui->r2_4);
    group3->addButton(ui->r3_4);
    group3->addButton(ui->r4_4);

    std::unique_ptr<QButtonGroup> group4 = std::make_unique<QButtonGroup>(this);
    group4->addButton(ui->r1_3);
    group4->addButton(ui->r2_3);
    group4->addButton(ui->r3_3);
    group4->addButton(ui->r4_3);

    std::unique_ptr<QButtonGroup> group5 = std::make_unique<QButtonGroup>(this);
    group5->addButton(ui->r1_5);
    group5->addButton(ui->r2_5);
    group5->addButton(ui->r3_5);
    group5->addButton(ui->r4_5);

    // Any other initialization code for your main window
}

// Rest of the code remains the same


MainWindow::~MainWindow()
{
delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  QMap<QString, QString> Res;
  Res["q1"] = "r1";    // Question 1
  Res["q1_2"] = "r3_2"; // Question 2
  Res["q1_4"] = "r4_4"; // Question 3
  Res["q1_3"] = "r3_3"; // Question 4
  Res["q1_5"] = "r4_5"; // Question 5
  int marks = 0;

  // Check the selected answers for each question and update the score

  // What we are checking here is that if these selected radio button name
  // is equal to the name present in our Map for that specific question.

  // Question 1
  if (Res[ui->q1->objectName()] == group1->checkedButton()->objectName())
      marks++;

  // Question 2
  if (Res[ui->q1_2->objectName()] == group2->checkedButton()->objectName())
      marks++;

  // Question 3
  if (Res[ui->q1_4->objectName()] == group3->checkedButton()->objectName())
      marks++;

  // Question 4
  if (Res[ui->q1_3->objectName()] == group4->checkedButton()->objectName())
      marks++;

  // Question 5
  if (Res[ui->q1_5->objectName()] == group5->checkedButton()->objectName())
      marks++;

  // Display the score to the user
  ui->Output->setText("Total Score: " + QString::number(marks) + " Out of 5");
}
