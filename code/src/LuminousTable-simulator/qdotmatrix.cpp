#include "qdotmatrix.h"

#include <QPainter>

QDotMatrix::QDotMatrix(QWidget *parent, int rowsCount, int colsCount, QColor backgroundColor) :
    QWidget(parent)
{
    mRowsCount = rowsCount;
    mColsCount = colsCount;
    mDotSize = 32;
    mIntensity = 0.5f;
    mBackgroundColor = backgroundColor;

    // matrix memory allocation
    mMatrix = new QColor*[mRowsCount];
    for (int x = 0; x < mRowsCount; ++x) {
        mMatrix[x] = new QColor[mColsCount];
    }

    for (int x = 0; x < mRowsCount; ++x) {
        for (int y = 0; y < mColsCount; ++y) {
            mMatrix[x][y] = mBackgroundColor;
        }
    }

    this->setFixedSize(rowsCount * mDotSize, colsCount * mDotSize);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    //add blur effect
    mGraphicsEffect = new QGraphicsBlurEffect();
    mGraphicsEffect->setBlurRadius(10);
    this->setGraphicsEffect(mGraphicsEffect);
}


void QDotMatrix::setColor(int x, int y, CRGB color)
{
    this->setColor(x, y, QColor(color.r, color.g, color.b));
}

void QDotMatrix::setColor(int x, int y, QColor color)
{
    mMatrix[x][y] = color;
}

void QDotMatrix::setIntensity(int value)
{
    mIntensity = (float)value / 255.0f;
}

void QDotMatrix::paintEvent(QPaintEvent * pe)
{
    QPainter painter(this);

    for (int x = 0; x < mRowsCount; ++x) {
        for (int y = 0; y < mColsCount; ++y) {

            int startX = x * mDotSize;
            int startY = y * mDotSize;
            int endX = startX + mDotSize;
            int endY = startY + mDotSize;

            QColor color = mMatrix[x][y];
            color.setRed(color.red() * mIntensity);
            color.setGreen(color.green() * mIntensity);
            color.setBlue(color.blue() * mIntensity);

            //color.setAlpha(mIntensity);
            painter.fillRect(QRect(startX, startY, endX, endY), color);

        }
    }
}
