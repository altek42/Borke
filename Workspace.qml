import QtQuick 2.8
import "Menu"
import "WebView"

Item {
    id:mainObject

    property int menuHeight: 30;
    property var mainWindow;
    Menu{
        id:menu;
        mainWindow:mainObject.mainWindow;
        width: mainObject.width;
        height: mainObject.menuHeight;
        z:webView.z+1;
    }

    WebView{
        id:webView;
        width: mainObject.width;
        height: mainObject.height - menu.height;
        y:menu.height;
    }
}
