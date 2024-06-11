#include <clip.h>
clip::clip(I2C* i2c, uint8_t addr, PwmOut& up, PwmOut& down) 
    : _i2c(i2c), _pwmServo(i2c, addr), map(0, 180, 250, 490), UP(up), Down(down) {
    
    // 構造函數體可以保持空白
}
void clip :: mainservo(int servonum, bool isopen ){
    if (isopen==true){ //300
        _pwmServo.setPWM(servonum,0,370);
    }
    else{           //475
        _pwmServo.setPWM(servonum,0,485);
    }
}
void clip::Lservo(int servonum, bool isopen){
    if (isopen==true){
        _pwmServo.setPWM(servonum,0,350);
    }
    else{
        _pwmServo.setPWM(servonum,0,475);
    }
}

void clip ::Rservo(int servonum, bool isopen){
    if (isopen==true){
        _pwmServo.setPWM(servonum,0,490);
    }
    else{
        _pwmServo.setPWM(servonum,0,390);
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
     Lservo(4, 0);
     Rservo(5, 0);
}
void clip:: CloseAll(){
     mainservo(0, 0);
     mainservo(1, 0);
     mainservo(2, 0);
     mainservo(3,0);
     Lservo(4, 1);
     Rservo(5, 1);
}

void clip ::setup(){
_pwmServo.begin();
_pwmServo.setPWMFreq(50);
// printf("Ready");
// n
// 490-250
// 490-350
// 左推出490
//右推出350
// 其490
}
void clip ::setDegree(int servonum, int degree){
  
float pwmValue = map.Calculate(degree);

printf("Test float value: %f\n", 123.4);

printf("Degree: %d\tPWM Value: %d.%d\n", degree, (int)pwmValue, (int)((pwmValue - (int)(pwmValue))*100));

_pwmServo.setPWM(servonum,0,pwmValue);


}

void clip::stopUP() {
    UP.write(0.0f);
}

void clip::stopDown() {
    Down.write(0.0f);
}

void clip::PushRod(bool UpDown) {
    if (UpDown == true) {
        stopDown();
        UP.write(0.9f);
        timeout.attach([this] { stopUP(); }, 2s); // 2秒后停止UP
    } else {
        stopUP();
        Down.write(0.9f);
        timeout.attach([this] { stopDown(); }, 2s); // 2秒后停止Down
    }
}



