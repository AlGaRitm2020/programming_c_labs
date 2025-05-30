#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include <functional>

class PlotWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlotWidget(QWidget *parent = nullptr);

    enum FunctionType {
        None,
        SinX,
        XSquared,
        XSinX,
        SinXSquared
    };

    void setFunction(FunctionType type);
    void zoomIn();
    void zoomOut();

protected:
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    FunctionType currentFunction = None;

    double minX = -10, maxX = 10;
    double minY = -5, maxY = 5;
    double offsetX = 0, offsetY = 0;

    QPoint lastMousePos;

    void drawAxes(QPainter &painter);
    void drawGraph(QPainter &painter);
};

#endif // PLOTWIDGET_H
