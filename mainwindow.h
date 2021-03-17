#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int EvaluateExpression(int firstNum, int secondNum, char operation);
    int OptimalFontSize();
    void ButtonClick();


    int FirstNum;
    char Operation;
    QList<QPushButton*> ButtonList;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
