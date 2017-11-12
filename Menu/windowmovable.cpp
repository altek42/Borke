#include "windowmovable.h"

void WindowMovable::initialize()
{
    qmlRegisterType<WindowMovable>("Menu", 1, 0, "WindowMovable");
}

WindowMovable::WindowMovable()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    this->_screenHeight = screenGeometry.height();
    this->_screenWidth = screenGeometry.width();
}

bool WindowMovable::eventFilter(QObject *sender, QEvent *event)
{
    switch (event->type()) {
    case QEvent::MouseMove:
        this->_mouseMove(static_cast<QMouseEvent*>(event));
        break;
    case QEvent::MouseButtonPress:
        this->_mouseButtonPress(static_cast<QMouseEvent*>(event));
        break;
    case QEvent::MouseButtonRelease:
        this->_mouseButtonRelease(static_cast<QMouseEvent*>(event));
        break;
    default:
        return false;
        break;
    }
    return true;
}

void WindowMovable::_setEventObject(QObject *obj)
{
    if(this->_eventObject){
        this->_eventObject->removeEventFilter(this);
    }
    this->_eventObject = obj;
    obj->installEventFilter(this);
}

QObject *WindowMovable::_getEbentObject()
{
    return this->_eventObject;
}

void WindowMovable::_setWindow(QObject *obj)
{
    this->_window = dynamic_cast<QQuickWindow*>(obj);
}

QObject *WindowMovable::_getWindow()
{
    return this->_window;
}

void WindowMovable::_mouseMove(QMouseEvent *event)
{
    this->_window->setX( this->_window->x() + event->x() - this->_lastMouseX  );
    this->_window->setY( this->_window->y() + event->y() - this->_lastMouseY  );
}

void WindowMovable::_mouseButtonRelease(QMouseEvent *event)
{
    this->_lastMouseX=0;
    this->_lastMouseY=0;
    this->_backWindowToScreen();
}

void WindowMovable::_mouseButtonPress(QMouseEvent *event)
{
    this->_lastMouseX = event->x();
    this->_lastMouseY = event->y();
}

void WindowMovable::_backWindowToScreen()
{
    if(this->_window->x() < 0){
        this->_window->setX(0);
    }
    else if(this->_window->x()+this->_window->width() > this->_screenWidth){
        this->_window->setX(this->_screenWidth - this->_window->width());
    }

    if(this->_window->y() < 0){
        this->_window->setY(0);
    }
    else if(this->_window->y()+this->_window->height() > this->_screenHeight){
        this->_window->setY(this->_screenHeight - this->_window->height());
    }
}
