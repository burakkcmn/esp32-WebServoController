#include "WebServerHandler.h"

WebServerHandler::WebServerHandler() : server(80), currentTime(0), previousTime(0) {}

void WebServerHandler::begin(ServoController* servoController) {
    this->servoController = servoController;
    server.begin();
}

void WebServerHandler::handleClient() {
    WiFiClient client = server.available();
    if (client) {
        currentTime = millis();
        previousTime = currentTime;
        Serial.println("New Client.");
        String currentLine = "";
        while (client.connected() && currentTime - previousTime <= timeoutTime) {
            currentTime = millis();
            if (client.available()) {
                char c = client.read();
                Serial.write(c);
                header += c;
                if (c == '\n') {
                    if (currentLine.length() == 0) {
                        handleRequest(client);
                        break;
                    } else {
                        currentLine = "";
                    }
                } else if (c != '\r') {
                    currentLine += c;
                }
            }
        }
        header = "";
        client.stop();
        Serial.println("Client disconnected.");
    }
}

void WebServerHandler::handleRequest(WiFiClient& client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE html><html>");
    client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    client.println("<link rel=\"icon\" href=\"data:,\">");
    client.println("<style>body { text-align: center; font-family: \"Trebuchet MS\", Arial; margin-left:auto; margin-right:auto;}");
    client.println(".slider { width: 300px; }</style>");
    client.println("<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>");
    client.println("</head><body><h1>ESP32 with Servo</h1>");
    client.println("<p>Position: <span id=\"servoPos\"></span></p>");
    client.println("<input type=\"range\" min=\"0\" max=\"180\" class=\"slider\" id=\"servoSlider\" onchange=\"servo(this.value)\"/>");
    client.println("<script>var slider = document.getElementById(\"servoSlider\");");
    client.println("var servoP = document.getElementById(\"servoPos\"); servoP.innerHTML = slider.value;");
    client.println("slider.oninput = function() { slider.value = this.value; servoP.innerHTML = this.value; }");
    client.println("$.ajaxSetup({timeout:1000}); function servo(pos) { $.get(\"/?value=\" + pos + \"&\"); {Connection: close};}</script>");
    client.println("</body></html>");
    
    if (header.indexOf("GET /?value=") >= 0) {
        int pos1 = header.indexOf('=');
        int pos2 = header.indexOf('&');
        String valueString = header.substring(pos1 + 1, pos2);
        servoController->write(valueString.toInt());
        Serial.println(valueString);
    }
    client.println();
}
