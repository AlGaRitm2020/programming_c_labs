#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override; // <-- Новое
    void keyPressEvent(QKeyEvent *event) override;

private:
    qreal rotation;
    int squareSize;
    QPoint squareCenter;
    qreal rotationDirection; // +1 по часовой, -1 против
    int delay;
    QTimer *timer;
};

#endif // MAINWINDOW_H
