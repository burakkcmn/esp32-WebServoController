#ifndef WEB_SERVER_HANDLER_H
#define WEB_SERVER_HANDLER_H

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include "ServoController.h"

class WebServerHandler {
public:
    WebServerHandler();
    void begin(ServoController* servoController);
    void handleClient();

private:
    WiFiServer server;
    String header;
    unsigned long currentTime;
    unsigned long previousTime;
    const long timeoutTime = 2000;
    ServoController* servoController;

    void handleRequest(WiFiClient& client);
};

#endif // WEB_SERVER_HANDLER_H
