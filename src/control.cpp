#include <stdio.h>
#include "pcatest.h"
#include "motortest.h"
#include <QMenuBar>
#include <QKeyEvent>

// keyPressEvent() rebuild
void control::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
       
            switch (event->key()) //determine which button get pressed
            {
            case Qt::Key_Up:
                SetMotorMode1(2000,2000,2000,2000);
                break;
            case Qt::Key_Down:
                setMotorMode1(-2000,-2000,-2000,-2000);  
                break;
            case Qt::Key_Left:
                 SetMotorMode1(-500,-500,2000,2000) ;
                break;
            case Qt::Key_Right:
                SetMotorMode1(2000,2000,-500,-500); 
                break;
            }
        
    }
}

void control::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
            switch (event->key()) //determine which button get loosed
            {
            case Qt::Key_Up:
                SetMotorMode1(0,0,0,0);         
                break;
            case Qt::Key_Down:
               SetMotorMode1(0,0,0,0);
                break;
            case Qt::Key_Left:
               SetMotorMode1(0,0,0,0);
                break;
            case Qt::Key_Right:
              SetMotorMode1(0,0,0,0);
                break;
            }
        
    }
}