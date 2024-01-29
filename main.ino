#include"week2.h"

#define motor_Right1 9
#define motor_Right2 8 
#define motor_Left1 4
#define motor_Left2 3
#define right_pwm 10
#define left_pwm 11
#define IR_Objects_Right 5
#define IR_Objects_Mid 6
#define IR_Objects_Left 7

int state = 0;
char moterstatus;
char sensorstatus;
SoftwareSerial BT(13 , 12);

motor motor(int motor_Right1, int motor_Right2, int right_pwm,
    int motor_Left1, int motor_Left2, int left_pwm);

sensor sensor(int IR_Objects_Right, int IR_Objects_Mid, int IR_Objects_Left);

void setup() 
{
  BT.begin(9600); 
}
void loop() 
{
  if(state == 0)
  {
    sensorstatus = sensor.sensor_read();
    
    switch(sensorstatus){
      case 1:
      motor.moveForward();
      break;
      case 2:
      motor.moveBack();
      break;
      case 3:
      motor.moveLeftSmall();
      break;
      case 4:
      motor.moveRighttSmall();
      case 5:
      motor.stop();
      state = 1;
    }
  }

  if(state == 1)
  {
    if (BT.available())
    {
      moterstatus=BT.read();
      Serial.println(moterstatus); 
    }
    
    switch (moterstatus)
    { 
      case 'F':
      Serial.println(moterstatus);
      motor.moveForward();
      break;
      case 'L':
      Serial.println(moterstatus);
      motor.moveLeft();
      break;
      case 'R':
      Serial.println(moterstatus);
      motor.moveRight();
      break;
      case 'B':
      Serial.println(moterstatus);
      motor.moveBack();
      break;
      
    }
  }
}