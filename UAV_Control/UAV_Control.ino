#include <Servo.h> 

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;

int Speed1 = 0;
int Speed2 = 0;
int Speed3 = 0;
int Speed4 = 0;

int MIN_SPEED = 550;


char cmd_arr[4];
char i = 0;   

void arm(){
 Servo1.write(0);
 Servo2.write(0);
 Servo3.write(0);
 Servo4.write(0);
}
           
void setup()
{
  
  Servo1.attach(3);
  Servo2.attach(6);
  Servo3.attach(9);
  Servo4.attach(11);

  Serial.begin(9600); 

  arm(); 

}

void loop()
{
  for(i=0;i<4;i++){
  while(Serial.available() < 1){}//wait here  
  cmd_arr[i] = Serial.read();
  }

  if(cmd_arr[0] < -49){
    while(1){
    Servo1.writeMicroseconds(0);
    Servo2.writeMicroseconds(0);
    Servo3.writeMicroseconds(0);
    Servo4.writeMicroseconds(0);
    }
  }
  else{  
    Speed1 = MIN_SPEED + ((cmd_arr[0] * 1900)/100) ;
    Speed2 = MIN_SPEED + ((cmd_arr[1] * 1900)/100) ;
    Speed3 = MIN_SPEED + ((cmd_arr[2] * 1900)/100) ;
    Speed4 = MIN_SPEED + ((cmd_arr[3] * 1900)/100) ;
    Servo1.writeMicroseconds(Speed1);
    Servo2.writeMicroseconds(Speed2);
    Servo3.writeMicroseconds(Speed3);
    Servo4.writeMicroseconds(Speed4);
  }
  



}






