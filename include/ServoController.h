#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <ESP32Servo.h>

class ServoController {
public:
    ServoController(int pin);
    void attach();
    void write(int value);

private:
    Servo myservo;
    int servoPin;
};

#endif // SERVO_CONTROLLER_H
