#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QBoxLayout>
#include <QDial>
#include <QVector>

#include "abstractsimulatorbehavior.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    // UI
    QWidget *mMainWidget;
    QBoxLayout *mMainLayout;
    QBoxLayout *mInputsLayout;
    QBoxLayout *mMatrixLayout;

    QPushButton *mButtonA;
    QDial *mPotentiometer;

    // Behaviours
    int mIndexBehavior;
    AbstractSimulatorBehavior *beahavior;

private slots:
    void onClickButtonA();

};

#endif // MAINWINDOW_H
