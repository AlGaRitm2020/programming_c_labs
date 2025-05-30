#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();       // CALCULATE
    void on_pushButton_2_clicked();     // Send to $1
    void on_pushButton_3_clicked();     // Send to $2
    void on_pushButton_4_clicked();
    void on_horizontalSlider_valueChanged(int value); // Slider changed
    void updateSecondNumber();          // When checkboxes change

private:
    Ui::MainWindow *ui;

    int getSecondNumberFromCheckboxes();
    void setFirstNumberToSlider(int value);
    void setSecondNumberToCheckboxes(int value);
};

#endif // MAINWINDOW_H
