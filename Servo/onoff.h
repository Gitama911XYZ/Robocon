#ifndef _ONOFF_H
#define _ONOFF_H

#include <mbed.h>
#include "Adafruit_PWMServoDriver.h"

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates


class onoff {
private:
    I2C* _i2c; // 儲存I2C對象的指針
    Adafruit_PWMServoDriver _pwmServo; // PWM servo driver實例

public:
onoff(I2C* i2c, uint8_t addr); // 構造函數，接受I2C對象和地址
void setup();
// void access(I2C* abc);
void mainservo(int servonum, bool isopen );
void Lservo(int servonum, bool isopen);
void Rservo(int servonum, bool isopen);


};



#endif
