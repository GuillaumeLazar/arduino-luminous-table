#ifndef QDOTMATRIX_H
#define QDOTMATRIX_H

#include <QWidget>

#include "FakeHardware.h"

class QDotMatrix : public QWidget
{
    Q_OBJECT
public:
    explicit QDotMatrix(QWidget *parent = 0, int rowsCount = 20, int colsCount = 10);

    void setColor(int x, int y, CRGB color);
    void setColor(int x, int y, QColor color);

protected:
    //override
    void paintEvent(QPaintEvent * pe);

    int mRowsCount;
    int mColsCount;
    int mDotSize;
    QColor **mMatrix;

signals:

public slots:

};

#endif // QDOTMATRIX_H
