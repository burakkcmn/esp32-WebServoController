#include "ServoController.h"

ServoController::ServoController(int pin) : servoPin(pin) {}

void ServoController::attach() {
    myservo.attach(servoPin);
}

void ServoController::write(int value) {
    myservo.write(value);
}
