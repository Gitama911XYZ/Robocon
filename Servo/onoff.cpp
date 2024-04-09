#include <onoff.h>
onoff::onoff(I2C* i2c, uint8_t addr) : _i2c(i2c), _pwmServo(i2c, addr) {
    // 構造函數體可以保持空白
}
void onoff :: mainservo(int servonum, bool isopen ){
    if (isopen==true){
        _pwmServo.setPWM(servonum,0,250);
    }
    else{           //475
        _pwmServo.setPWM(servonum,0,465);
    }
}
void onoff::Lservo(int servonum, bool isopen){
    if (isopen==true){
        _pwmServo.setPWM(servonum,0,350);
    }
    else{
        _pwmServo.setPWM(servonum,0,490);
    }
}

void onoff::Rservo(int servonum, bool isopen){
    if (isopen==true){
        _pwmServo.setPWM(servonum,0,490);
    }
    else{
        _pwmServo.setPWM(servonum,0,400);
    }
}   
// void onoff::access(I2C* abc){
//     abcd = abc;
// }

void onoff::setup(){
_pwmServo.begin();
_pwmServo.setPWMFreq(50);
printf("Ready");
// n
// 490-250
// 490-350
// 左推出490
//右推出350
// 其490
}
