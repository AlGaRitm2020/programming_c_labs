#include "mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    rotation(0),
    squareSize(100),
    rotationDirection(1),
    delay(16),
    timer(new QTimer(this))
{
    squareCenter = rect().center();

    connect(timer, &QTimer::timeout, this, [this](){
        rotation += rotationDirection * 2;
        if (rotation >= 360) rotation -= 360;
        if (rotation < 0) rotation += 360;
        update();
    });

    timer->start(delay);

    setMouseTracking(true);
}

MainWindow::~MainWindow() = default;

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(squareCenter);
    painter.rotate(rotation);

    QRect rect(-squareSize / 2, -squareSize / 2, squareSize, squareSize);

    painter.setBrush(Qt::gray);
    painter.setPen(Qt::black);
    painter.drawRect(rect);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    squareCenter = event->pos();
    update();
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    int delta = event->angleDelta().y();
    if (delta > 0)
        squareSize += 5;
    else if (delta < 0 && squareSize > 10)
        squareSize -= 5;

    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        rotationDirection = 1; // По часовой
    } else if (event->button() == Qt::RightButton) {
        rotationDirection = -1; // Против часовой
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up) {
        delay -= 5;
        if (delay > 1000) delay = 1000;
    } else if (event->key() == Qt::Key_Down) {
        delay += 5;
        if (delay < 1) delay = 1;
    }

    timer->setInterval(delay); // Обновляем задержку
}
