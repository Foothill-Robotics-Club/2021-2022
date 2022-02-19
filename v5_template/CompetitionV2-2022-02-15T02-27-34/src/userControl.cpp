#include "vex.h"

extern controller Controller1;
extern digital_out DigitalOutA;
extern digital_out DigitalOutB;
extern brain Brain;
extern motor_group LeftMotors;



void userControl(){
  Brain.Screen.print("User Control");
  while (true) {
    

    if (Controller1.ButtonL1.pressing()) {
      DigitalOutA.set(true); 
      DigitalOutB.set(true);
    }

    else if (Controller1.ButtonL2.pressing()) {
      DigitalOutA.set(false); 
      DigitalOutB.set(false);
    }
    LeftMotors.spin(forward,Controller1.Axis3.value(), velocityUnits::pct);
    RightMotors.spin(forward,Controller1.Axis2.value(), velocityUnits::pct);

    wait(20, msec); 
  }
}