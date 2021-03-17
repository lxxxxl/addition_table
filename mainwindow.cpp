#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    this->FirstNum = 1;
    this->Operation = '+';

    ui->setupUi(this);


    for (int i = 1; i < 10; i++)
    {
        QPushButton *button = new QPushButton(this);


        // set text
        QString text = QString("%1 %2 %3").arg(this->FirstNum)
                                          .arg(this->Operation)
                                          .arg(i);
        int result = this->EvaluateExpression(this->FirstNum, i, this->Operation);
        text += QString(" = %1").arg(result);
        button->setText(text);

        // set font
        QFont font = button->font();
        font.setPointSize(24);
        font.setBold(true);
        button->setFont(font);

        // set style
        button->setFlat(true);

        // connect signal-slot
        connect(button, &QPushButton::released, this, &MainWindow::ButtonClick);


        // add button to UI
        ui->verticalLayout->addWidget(button);
        this->ButtonList.append(button);
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::EvaluateExpression(int firstNum, int secondNum, char operation)
{
    switch (operation){
    case '+':
        return firstNum + secondNum;
    default:
        return 0;
    }
}

int MainWindow::OptimalFontSize()
{
    /*QScreen *screen = QApplication::screens().at(0);
    int width = screen->size().width();
    int height = screen->size().height();*/
    // TODO
    return 0;
}

void MainWindow::ButtonClick()
{
    QObject *sender = QObject::sender();
    foreach (QPushButton* button, this->ButtonList)
    {
        if (sender != button)
            button->setEnabled(false);

    }

}
