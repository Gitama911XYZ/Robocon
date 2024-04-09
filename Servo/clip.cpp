#include <clip.h>
clip::clip(I2C* i2c, uint8_t addr) : _i2c(i2c), _pwmServo(i2c, addr) {
    // 構造函數體可以保持空白
}
void clip :: mainservo(int servonum, bool isopen ){
    if (isopen==true){
        _pwmServo.setPWM(servonum,0,250);
    }
    else{           //475
        _pwmServo.setPWM(servonum,0,465);
    }
}
void clip::Lservo(int servonum, bool isopen){
    if (isopen==true){
        _pwmServo.setPWM(servonum,0,350);
    }
    else{
        _pwmServo.setPWM(servonum,0,490);
    }
}

void clip ::Rservo(int servonum, bool isopen){
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
void clip:: Set1(bool isopen){
    if (isopen==true){
      mainservo(0, 1); 
      mainservo(2, 1);  
    }
    else{
      mainservo(0, 0); 
      mainservo(2, 0);  
    }
}
void clip:: Set2(bool isopen){
    if (isopen==true){
      mainservo(1, 1); 
      mainservo(3, 1);  
    }
    else{
      mainservo(1, 0); 
      mainservo(3, 0);  
    }
}
void clip:: OpenAll(){
     mainservo(0, 1);
     mainservo(1, 1);
     mainservo(2, 1);
     mainservo(3,1);
     Lservo(4, 1);
     Rservo(5, 1);
}
void clip:: CloseAll(){
     mainservo(0, 0);
     mainservo(1, 0);
     mainservo(2, 0);
     mainservo(3,0);
     Lservo(4, 0);
     Rservo(5, 0);
}

void clip ::setup(){
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
