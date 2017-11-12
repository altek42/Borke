import QtQuick 2.8

Item {
    id:mainObject;
    property int size;
    property string imageSource;

    signal pressed;

    onSizeChanged: {
        mainObject.width = size;
        mainObject.height = size;
    }

    QtObject{
        id:_private;
        property string hoverColor: '#77000000';
    }

    Rectangle{
        id:background;
        anchors.fill: parent;
        color: _private.hoverColor;
        visible: false;
    }
    MouseArea{
        anchors.fill: parent;
        hoverEnabled: true;
        onEntered: {background.visible = true;}
        onExited: {background.visible = false;}
        onPressed: {mainObject.pressed();}
    }
    Image{
        id:image;
        anchors.fill: parent;
        source: mainObject.imageSource;
        fillMode: Image.PreserveAspectFit;
    }
}
