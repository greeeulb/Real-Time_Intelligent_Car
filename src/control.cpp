#include <stdio.h>
#include "pcatest.h"
#include "motortest.h"

// keyPressEvent() rebuild
void control::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(mKeyFlag)//whether press ctrl
        {
            switch (event->key()) //determine which button get pressed
            {
            case Qt::Key_Left:
                on_BtnCcw_clicked();
                break;
            case Qt::Key_Right:
                on_BtnCw_clicked();
                break;
            }
        }
        else
        {
            switch (event->key()) //determine which button get pressed
            {
            case Qt::Key_Up:
                on_BtnGo_clicked();
                break;
            case Qt::Key_Down:
                on_BtnBack_clicked();
                break;
            case Qt::Key_Left:
                on_BtnLeft_clicked();
                break;
            case Qt::Key_Right:
                on_BtnRight_clicked();
                break;
            case Qt::Key_Z:
                on_BtnSpeedUp_clicked();
                break;
            case Qt::Key_X:
                on_BtnSpeedDown_clicked();
                break;
            case Qt::Key_Control:	//if pressed Ctrl, set mKeyFlag to true
                mKeyFlag = true;
                break;
            }
        }
    }
}
// keyReleaseEvent()rebuild
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(mKeyFlag)//whether pressed ctrl
        {
            switch (event->key()) //determine which button get loosed
            {
            case Qt::Key_Left:
                getStraight();
                break;
            case Qt::Key_Right:
                getStraight();
                break;
            case Qt::Key_Control:
                mKeyFlag = false;	//if loose Ctrl, set mKeyFlag to false
                break;
            }
        }
        else
        {
            switch (event->key()) //determine which button get loosed
            {
            case Qt::Key_Up:
                on_BtnStop_clicked();
                break;
            case Qt::Key_Down:
                on_BtnStop_clicked();
                break;
            case Qt::Key_Left:
                getStraight();
                break;
            case Qt::Key_Right:
                getStraight();
                break;
            }
        }
    }
}
