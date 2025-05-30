#include "plotwidget.h"
#include <QPainter>
#include <QWheelEvent>
#include <cmath>

PlotWidget::PlotWidget(QWidget *parent)
    : QWidget(parent)
{}

void PlotWidget::setFunction(FunctionType type)
{
    currentFunction = type;
    update();
}

void PlotWidget::zoomIn()
{
    double factor = 1.1;
    minX += (maxX - minX) / factor / 2;
    maxX -= (maxX - minX) / factor / 2;
    minY += (maxY - minY) / factor / 2;
    maxY -= (maxY - minY) / factor / 2;
    update();
}

void PlotWidget::zoomOut()
{
    double factor = 1.1;
    minX -= (maxX - minX) / factor / 2;
    maxX += (maxX - minX) / factor / 2;
    minY -= (maxY - minY) / factor / 2;
    maxY += (maxY - minY) / factor / 2;
    update();
}

void PlotWidget::drawAxes(QPainter &painter)
{
    int w = width();
    int h = height();

    double dx = maxX - minX;
    double dy = maxY - minY;

    // Ось X
    double yZero = (1.0 - (-offsetY - minY) / dy) * h;
    if (yZero >= 0 && yZero <= h) {
        painter.setPen(Qt::black);
        painter.drawLine(0, yZero, w, yZero);
        painter.drawLine(w - 10, yZero - 5, w, yZero);
        painter.drawLine(w - 10, yZero + 5, w, yZero);
    }

    // Ось Y
    double xZero = (0 - minX - offsetX) / dx * w;
    if (xZero >= 0 && xZero <= w) {
        painter.drawLine(xZero, 0, xZero, h);
        painter.drawLine(xZero - 5, 10, xZero, 0);
        painter.drawLine(xZero + 5, 10, xZero, 0);
    }
}

void PlotWidget::drawGraph(QPainter &painter)
{
    int w = width();
    int h = height();

    double dx = maxX - minX;
    double dy = maxY - minY;

    QPen pen(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);

    QVector<QPointF> points;

    for (int i = 0; i < w; ++i) {
        double x = minX + (maxX - minX) * i / w + offsetX;
        double yVal = 0;

        switch (currentFunction) {
        case None: return;
        case SinX: yVal = sin(x); break;
        case XSquared: yVal = x * x; break;
        case XSinX: yVal = x * sin(x); break;
        case SinXSquared: yVal = sin(x * x); break;
        }

        double y = (1.0 - (yVal - minY - offsetY) / dy) * h;
        if (std::isfinite(y))
            points.append(QPointF(i, y));
    }

    painter.drawPolyline(points.data(), points.size());
}

void PlotWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawAxes(painter);
    drawGraph(painter);
}

void PlotWidget::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0)
        zoomIn();
    else
        zoomOut();
}

void PlotWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        lastMousePos = event->pos();
}

void PlotWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPoint delta = event->pos() - lastMousePos;
        lastMousePos = event->pos();

        double dx = (maxX - minX) / width();
        double dy = (maxY - minY) / height();

        offsetX -= delta.x() * dx;
        offsetY += delta.y() * dy;

        update();
    }
}
