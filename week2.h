#pragma once
#ifndef _week2_H_
#define _week2_H_
#include <SoftwareSerial.h>
#include<Wire.h>
class sensor
{
private:
    int _IR_Objects_Right;
    int _IR_Objects_Mid;
    int _IR_Objects_Left;
public:
    sensor(int IR_Objects_Right, int IR_Objects_Mid, int IR_Objects_Left);
    int sensor_read();
};

class motor
{
private:
    int _motor_Right1;
    int _motor_Right2;
    int _right_pwm;
    int _motor_Left1;
    int _motor_Left2;
    int _left_pwm;

public:
    motor(int motor_Right1, int motor_Right2, int right_pwm,
        int motor_Left1, int motor_Left2, int left_pwm);
    void moveForward();
    void moveBack();
    void moveRight();
    void moveRightSmall();
    void moveLeft();
    void moveLeftSmall();
    void Stop();
};

#endif // !_week2_H_

