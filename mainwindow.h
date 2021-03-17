#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "speaker.h"

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
    void SpeakDone();
    QPixmap ButtonLabel(QString expression, QString result, bool highlight);


    int SentenceDelay;
    int FirstNum;
    char Operation;
    QList<QPushButton*> ButtonList;
    Speaker *speaker;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
