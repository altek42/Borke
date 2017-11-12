#ifndef MENUBAR_H
#define MENUBAR_H

#include <QQuickItem>
#include <QDebug>
#include <QQuickWindow>
#include <QGuiApplication>
#include <QScreen>

class WindowMovable : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QObject* eventObject READ _getEbentObject WRITE _setEventObject)
    Q_PROPERTY(QObject* window READ _getWindow WRITE _setWindow)
private:
    QObject* _eventObject=nullptr;
    QQuickWindow* _window=nullptr;

    int _lastMouseX =0;
    int _lastMouseY =0;
    int _screenWidth;
    int _screenHeight;
public:
    static void initialize();
    WindowMovable();
    virtual bool eventFilter(QObject *object, QEvent *event) override;
private:
    void _setEventObject(QObject* obj);
    QObject* _getEbentObject();

    void _setWindow(QObject* obj);
    QObject* _getWindow();

    void _mouseMove(QMouseEvent *event);
    void _mouseButtonRelease(QMouseEvent *event);
    void _mouseButtonPress(QMouseEvent *event);
    void _backWindowToScreen();
signals:

public slots:

};

#endif // MENUBAR_H
