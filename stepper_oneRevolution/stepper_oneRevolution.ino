  
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

bool flag = false;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 1, 2, 3, 4);

void setup() {
  pinMode(0, INPUT);
  // set the speed at 60 rpm:
  myStepper.setSpeed(120);
}

void loop() {
  if(digitalRead(0) == true){
    flag = true;
  }
  else if(digitalRead(0) == false){
    flag = false;
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }
  while(flag == true){
    // step one revolution  in one direction:
    myStepper.step(-1);
    if(digitalRead(0) == false){
      flag = false;
      digitalWrite(1,LOW);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      break;
    }
  }
}

