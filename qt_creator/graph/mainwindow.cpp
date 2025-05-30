#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotwidget.h"
#include <cmath>

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent), ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);

//     PlotWidget* plot = findChild<PlotWidget*>("plotArea");
//     if (plot) {
//         plot->setFunction([](double x) { return std::sin(x); });
//     }
// }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    PlotWidget* plot = findChild<PlotWidget*>("plotArea");
    if (plot) plot->zoomIn();
}

void MainWindow::on_pushButton_2_clicked()
{
    PlotWidget* plot = findChild<PlotWidget*>("plotArea");
    if (plot) plot->zoomOut();
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onRenderButtonClicked);
}


void MainWindow::onRenderButtonClicked()
{
    PlotWidget::FunctionType funcType = PlotWidget::None;

    if (ui->radioButton->isChecked()) {
        funcType = PlotWidget::XSinX;
    } else if (ui->radioButton_2->isChecked()) {
        funcType = PlotWidget::SinXSquared;
    } else if (ui->radioButton_3->isChecked()) {
        funcType = PlotWidget::SinX;
    } else if (ui->radioButton_4->isChecked()) {
        funcType = PlotWidget::XSquared;
    }

    ui->plotArea->setFunction(funcType);
}
