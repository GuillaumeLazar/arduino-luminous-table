#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QBoxLayout>
#include <QDial>
#include <QSlider>
#include <QVector>

#include "AbstractTableBehavior.h"

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
    QPushButton *mButtonB;
    QDial *mPotentiometer;
    QSlider *mSoundLevel;

    // Behaviours
    int mIndexBehavior;
    AbstractTableBehavior *beahavior;

    void createNextBehavior();

private slots:
    void onClickButtonA();
    void onClickButtonB();
    void onSoundLevelChanged(int value);
    void onPotentionmeterChanged(int value);


};

#endif // MAINWINDOW_H
