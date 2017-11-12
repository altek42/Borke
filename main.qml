import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    id:mainWindow;
    visible: true
    width: 300
    height: 260
    title: qsTr("Borke");
    flags: Qt.WindowStaysOnTopHint | Qt.Window | Qt.FramelessWindowHint | Qt.NoDropShadowWindowHint ;


    Workspace {
        anchors.fill: parent;
        mainWindow: mainWindow;
        menuHeight: 25;
    }
}
