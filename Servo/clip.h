#ifndef _CLIP_H
#define _CLIP_H

#include <mbed.h>
#include "Adafruit_PWMServoDriver.h"

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates


class clip {
private:
    I2C* _i2c; // 儲存I2C對象的指針
    Adafruit_PWMServoDriver _pwmServo; // PWM servo driver實例

public:
clip(I2C* i2c, uint8_t addr); // 構造函數，接受I2C對象和地址
void setup();
// void access(I2C* abc);
void mainservo(int servonum, bool isopen );
void Lservo(int servonum, bool isopen);
void Rservo(int servonum, bool isopen);
void Set1(bool isopen);
void Set2(bool isopen);
void OpenAll();
void CloseAll();


};



#endif
