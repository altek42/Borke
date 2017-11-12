import QtQuick 2.8
import Menu 1.0
import QtQuick.Window 2.2

Item{
    id:mainObject
    property var mainWindow;

    Rectangle{
        color: '#E62117';
        anchors.fill: parent;
    }

    WindowMovable{
        eventObject: mouseArea;
        window: mainObject.mainWindow;
    }

    MouseArea{
        id:mouseArea;
        anchors.fill: parent;
    }

    Text{
        x:10;
        text: mainWindow.title;
        font.pixelSize: mainObject.height -5;
        font.family: titleFont.name;
        FontLoader {
            id: titleFont;
            source: "qrc:/Fonts/titleFont.ttf"
        }
    }

    MenuButton{
        id:exitButton;
        size: mainObject.height;
        anchors.right: mainObject.right;
        imageSource: "qrc:/Images/exit_button.png";

        onPressed: {
            Qt.quit();
        }
    }
    MenuButton{
        size: mainObject.height;
        anchors.right: exitButton.left;
        imageSource: "qrc:/Images/minimize_button.png";

        onPressed: {
            mainWindow.visibility = Window.Minimized;
        }
    }

}
