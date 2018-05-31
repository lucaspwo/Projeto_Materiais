  
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
#define BTN 0
#define IN1 1
#define IN2 2
#define IN3 3
#define IN4 4

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

bool flag = false;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, IN1, IN2, IN3, IN4);

void setup() {
  pinMode(BTN, INPUT);
  // set the speed at 60 rpm:
  myStepper.setSpeed(120);
}

void stepperOFF(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void loop() {
  if(digitalRead(BTN) == true){
    flag = true;
//    myStepper.step(1);
  }
  else if(digitalRead(BTN) == false){
    flag = false;
    stepperOFF();
  }
  while(flag == true){
    // step one revolution  in one direction:
    myStepper.step(-1);
    if(digitalRead(BTN) == false){
      flag = false;
      stepperOFF();
      break;
    }
  }
}

