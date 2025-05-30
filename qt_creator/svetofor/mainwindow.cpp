#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentState(0)
{
    ui->setupUi(this);

    // Set initial state of all lights to off (grey)
    ui->frame_4->setStyleSheet("background: grey; border-radius: 50px;");
    ui->frame_5->setStyleSheet("background: grey; border-radius: 50px;");
    ui->frame_3->setStyleSheet("background: grey; border-radius: 50px;");

    // Setup timer to trigger every 2 seconds
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLights);
    timer->start(2000);  // 2 seconds
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLights()
{

    ui->frame_4->setStyleSheet("background: grey; border-radius: 50px;");
    ui->frame_5->setStyleSheet("background: grey; border-radius: 50px;");
    ui->frame_3->setStyleSheet("background: grey; border-radius: 50px;");

    switch(currentState) {
    case 0: // Red
        ui->frame_4->setStyleSheet("background: red; border-radius: 50px;");
        break;
    case 1: // Yellow
        ui->frame_5->setStyleSheet("background: yellow; border-radius: 50px;");
        break;
    case 2: // Green
        ui->frame_3->setStyleSheet("background: green; border-radius: 50px;");
        break;
    case 3: // Yellow again
        ui->frame_5->setStyleSheet("background: yellow; border-radius: 50px;");
        break;
    }

    currentState = (currentState + 1) % 4; // Cycle between 0-3
}
