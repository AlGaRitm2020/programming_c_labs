#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);

    connect(ui->horizontalSlider_2, &QSlider::valueChanged, this, &MainWindow::on_horizontalSlider_valueChanged);

    // Connect checkboxes to real-time update
    connect(ui->checkBox, &QCheckBox::toggled, this, &MainWindow::updateSecondNumber);
    connect(ui->checkBox_2, &QCheckBox::toggled, this, &MainWindow::updateSecondNumber);
    connect(ui->checkBox_3, &QCheckBox::toggled, this, &MainWindow::updateSecondNumber);
    connect(ui->checkBox_4, &QCheckBox::toggled, this, &MainWindow::updateSecondNumber);
    connect(ui->checkBox_5, &QCheckBox::toggled, this, &MainWindow::updateSecondNumber);
    connect(ui->checkBox_6, &QCheckBox::toggled, this, &MainWindow::updateSecondNumber);
    connect(ui->checkBox_7, &QCheckBox::toggled, this, &MainWindow::updateSecondNumber);
    connect(ui->checkBox_8, &QCheckBox::toggled, this, &MainWindow::updateSecondNumber);

    // Initial display
    on_horizontalSlider_valueChanged(ui->horizontalSlider_2->value());
    updateSecondNumber();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}

void MainWindow::updateSecondNumber()
{
    int value = getSecondNumberFromCheckboxes();
    ui->lcdNumber_2->display(value);
}

void MainWindow::on_pushButton_clicked()
{
    int num1 = ui->horizontalSlider_2->value();
    int num2 = getSecondNumberFromCheckboxes();

    double result = 0;
    if (ui->radioButton->isChecked()) {        // Add
        result = num1 + num2;
    } else if (ui->radioButton_2->isChecked()) { // Sub
        result = num1 - num2;
    } else if (ui->radioButton_3->isChecked()) { // Div
        if (num2 != 0) {
            result = static_cast<double>(num1) / num2;
        } else {
            ui->textBrowser->setText("Error: Division by zero");
            return;
        }
    } else if (ui->radioButton_4->isChecked()) { // Mul
        result = num1 * num2;
    } else {
        ui->textBrowser->setText("Select operation");
        return;
    }

    // Show result
    ui->textBrowser->setText(QString::number(result));

}

int MainWindow::getSecondNumberFromCheckboxes()
{
    int value = 0;
    if (ui->checkBox->isChecked()) value += 1;
    if (ui->checkBox_2->isChecked()) value += 2;
    if (ui->checkBox_3->isChecked()) value += 4;
    if (ui->checkBox_4->isChecked()) value += 8;
    if (ui->checkBox_5->isChecked()) value += 16;
    if (ui->checkBox_6->isChecked()) value += 32;
    if (ui->checkBox_7->isChecked()) value += 64;
    if (ui->checkBox_8->isChecked()) value += 128;
    return value;
}

void MainWindow::setFirstNumberToSlider(int value)
{
    ui->horizontalSlider_2->setValue(value);
}

void MainWindow::setSecondNumberToCheckboxes(int value)
{
    ui->checkBox->setChecked(value & 1);
    ui->checkBox_2->setChecked(value & 2);
    ui->checkBox_3->setChecked(value & 4);
    ui->checkBox_4->setChecked(value & 8);
    ui->checkBox_5->setChecked(value & 16);
    ui->checkBox_6->setChecked(value & 32);
    ui->checkBox_7->setChecked(value & 64);
    ui->checkBox_8->setChecked(value & 128);
}

void MainWindow::on_pushButton_2_clicked() // Send to $1
{
    bool ok;
    int result = ui->textBrowser->toPlainText().toInt(&ok);
    if (ok) {
        ui->horizontalSlider_2->setValue(result);
        on_horizontalSlider_valueChanged(result);
    }
}

void MainWindow::on_pushButton_3_clicked() // Send to $2
{
    bool ok;
    int result = ui->textBrowser->toPlainText().toInt(&ok);
    if (ok) {
        setSecondNumberToCheckboxes(result);
        updateSecondNumber();
    }
}

void MainWindow::on_pushButton_4_clicked() // Send to $2
{
    ui->textBrowser->setText(QString::number(0));
}
