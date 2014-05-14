#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "qdotmatrix.h"
#include "FakeHardware.h"

//TODO: put this in a separate file
struct FakeFastLED {
    QDotMatrix *dotMatrix;
    void show()
    {
        dotMatrix->update();
    }
};

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
    void init();
    int random(int high);
    void delay(int milliseconds);
    void readPotentiometerAndButton();

    Ui::MainWindow *ui;
    QDotMatrix *mDotMatrix;
    QTimer *mTimer;
    FakeFastLED FastLED;


private slots:
    void loop();

};

#endif // MAINWINDOW_H
