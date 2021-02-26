/*
 * Modified by Yuqing Yang
 * Modified from ServoMotors.pdf in class
 * Thiscode works with a continuous servo motor 
 * It makes the servo arm rotate automatically
 */

#include <Servo.h>

Servo servoMotor;       // creates an instance of the servo object to control a servo

void setup() {
  servoMotor.attach(9);       // attaches the servo on pin 9 to the servo object
} 
 
void loop() {
  servoMotor.write(85);    //control the speed of rotating

}
