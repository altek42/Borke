import QtQuick 2.8
import QtWebEngine 1.5

WebEngineView{
    id:webEngine;
    url: "https://youtube.com"
    profile:  WebEngineProfile{
            httpUserAgent: "Mozilla/5.0 (Linux; Android 7.0; SAMSUNG SM-G950F Build/NRD90M) AppleWebKit/537.36 (KHTML, like Gecko) SamsungBrowser/5.2 Chrome/51.0.2704.106 Mobile Safari/537.36"

    }
    userScripts: [overflowHidden]

    WebEngineScript {
        id:overflowHidden;
        sourceCode: "document.body.style.overflowX = 'hidden'"
        injectionPoint: WebEngineScript.DocumentReady
        worldId: WebEngineScript.MainWorld
    }
}
