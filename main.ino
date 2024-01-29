#include"week2.h"

#define MOTOR_RIGHT1 9
#define MOTOR_RIGHT2 8 
#define MOTOR_LEFT1 4
#define MOTOR_LEFT2 3
#define RIGHT_PWM 10
#define LEFT_PWM 11
#define IR_OBJECTS_RIGHT 5
#define IR_OBJECTS_MID 6
#define IR_OBJECTS_LEFT 7

int state = 0;
char motorstatus;
char sensorstatus;
SoftwareSerial BT(13 , 12);

Motor motor(int MOTOR_RIGHT1, int MOTOR_RIGHT2, int RIGHT_PWM,
    int MOTOR_LEFT1, int MOTOR_LEFT2, int LEFT_PWM);

Sensor sensor(int IR_OBJECTS_RIGHT, int IR_OBJECTS_MID, int IR_OBJECTS_LEFT);

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
        break;
      case 5:
        motor.stop();
        state = 1;
        break;
    }
  }

  if(state == 1)
  {
    if (BT.available())
    {
      motorstatus=BT.read();
      Serial.println(motorstatus); 
    }
    
    switch (motorstatus)
    { 
      case 'F':
        Serial.println(motorstatus);
        motor.moveForward();
        break;
      case 'L':
        Serial.println(motorstatus);
        motor.moveLeft();
        break;
      case 'R':
        Serial.println(motorstatus);
        motor.moveRight();
        break;
      case 'B':
        Serial.println(motorstatus);
        motor.moveBack();
        break;
      
    }
  }
}