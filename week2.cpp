#include "week2.h"
#include "Arduino.h"

Motor::motor(int motor_Right1, int motor_Right2, int right_pwm,
    int motor_Left1, int motor_Left2, int left_pwm)
{
    pinMode(motor_Right1, OUTPUT);
    pinMode(motor_Right2, OUTPUT);
    pinMode(motor_Left1, OUTPUT);
    pinMode(motor_Left2, OUTPUT);
    pinMode(left_pwm, OUTPUT);
    pinMode(right_pwm, OUTPUT);

    _motor_Right1 = motor_Right1;
    _motor_Right2 = motor_Right2;
    _motor_Left1 = motor_Left1;
    _motor_Left2 = motor_Left2;
    _right_pwm = right_pwm;
    _left_pwm = left_pwm;
}

void Motor::moveForward()
{
    digitalWrite(_motor_Left2, HIGH);
    digitalWrite(_motor_Left1, LOW);
    digitalWrite(_motor_Right2, HIGH);
    digitalWrite(_motor_Right1, LOW);
    analogWrite(_right_pwm, 99);
    analogWrite(_left_pwm, 100);
    delay(180);
    Stop();
}

void Motor::moveBack()
{
    digitalWrite(_motor_Left2, LOW);
    digitalWrite(_motor_Left1, HIGH);
    digitalWrite(_motor_Right2, LOW);
    digitalWrite(_motor_Right1, HIGH);
    analogWrite(_right_pwm, 90);
    analogWrite(_left_pwm, 90);
    delay(140);
    Stop();
}

void Motor::moveLeft()
{
    digitalWrite(_motor_Left2, LOW);
    digitalWrite(_motor_Left1, LOW);
    digitalWrite(_motor_Right2, HIGH);
    digitalWrite(_motor_Right1, LOW);
    analogWrite(_right_pwm, 90);
    analogWrite(_left_pwm, 115);
    delay(200);
    Stop();
}

void Motor::moveLeftSmall()
{
    digitalWrite(_motor_Left2, LOW);
    digitalWrite(_motor_Left1, LOW);
    digitalWrite(_motor_Right2, HIGH);
    digitalWrite(_motor_Right1, LOW);
    analogWrite(_right_pwm, 90);
    analogWrite(_left_pwm, 95);
    delay(200);
    Stop();
}

void Motor::moveRight()
{
    digitalWrite(_motor_Left2,HIGH);
    digitalWrite(_motor_Left1,LOW);
    digitalWrite(_motor_Right2,LOW);
    digitalWrite(_motor_Right1,LOW);
    analogWrite(_right_pwm, 105);
    analogWrite(_left_pwm, 90);
    delay(200);
    Stop();
}

void Motor::moveRightSmall()
{
    digitalWrite(_motor_Left2, HIGH);
    digitalWrite(_motor_Left1, LOW);
    digitalWrite(_motor_Right2, LOW);
    digitalWrite(_motor_Right1, LOW);
    analogWrite(_right_pwm, 70);
    analogWrite(_left_pwm, 90);
    delay(150);
    Stop();
}

void Motor::Stop()
{
    digitalWrite(_motor_Left1, LOW);
    digitalWrite(_motor_Left2, LOW);
    digitalWrite(_motor_Right1, LOW);
    digitalWrite(_motor_Right2, LOW);
}

Sensor::sensor(int IR_Objects_Right, int IR_Objects_Mid, int IR_Objects_Left)
{
    pinMode(IR_Objects_Right, INPUT);
    pinMode(IR_Objects_Mid, INPUT);
    pinMode(IR_Objects_Left, INPUT);

    _IR_Objects_Right = IR_Objects_Right;
    _IR_Objects_Mid = IR_Objects_Mid;
    _IR_Objects_Left = IR_Objects_Left;
}

int Sensor::sensor_read() {
    if (digitalRead(_IR_Objects_Right) == 1 && digitalRead(_IR_Objects_Mid) == 0 && digitalRead(_IR_Objects_Left) == 1) {
        return 1;
    }
    if (digitalRead(_IR_Objects_Right) == 1 && digitalRead(_IR_Objects_Mid) == 1 && digitalRead(_IR_Objects_Left) == 0) {
        return 2;
    }
    if (digitalRead(_IR_Objects_Right) == 0 && digitalRead(_IR_Objects_Mid) == 1 && digitalRead(_IR_Objects_Left) == 1) {
        return 3;
    }
    if (digitalRead(_IR_Objects_Right) == 1 && digitalRead(_IR_Objects_Mid) == 1 && digitalRead(_IR_Objects_Left) == 1) {
        return 4;
    }
    if (digitalRead(_IR_Objects_Right) == 0 && digitalRead(_IR_Objects_Mid) == 0 && digitalRead(_IR_Objects_Left) == 0) {
        return 5;
    }
    if (digitalRead(_IR_Objects_Right) == 1 && digitalRead(_IR_Objects_Mid) == 0 && digitalRead(_IR_Objects_Left) == 0) {
        return 5;
    }
    if (digitalRead(_IR_Objects_Right) == 0 && digitalRead(_IR_Objects_Mid) == 0 && digitalRead(_IR_Objects_Left) == 1) {
        return 5;
    }

    return -1;
}