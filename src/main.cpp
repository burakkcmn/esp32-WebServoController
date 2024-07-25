#include <Arduino.h>
#include "WiFiHandler.h"
#include "WebServerHandler.h"
#include "ServoController.h"

WiFiManager wifiManager;
WebServerHandler webServerHandler;
ServoController servoController(13);  // GPIO the servo is attached to

void setup() {
    Serial.begin(115200);
    servoController.attach();
    wifiManager.connect();
    webServerHandler.begin(&servoController);
}

void loop() {
    webServerHandler.handleClient();
}
