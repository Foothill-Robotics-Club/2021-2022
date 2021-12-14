/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lym20                                            */
/*    Created:      Mon Oct 18 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
vex::controller Controller;
vex::competition Competition;
vex::motor LeftMotor = vex::motor(PORT1);
vex::motor RightMotor = vex::motor(PORT2);

void intake(){

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //LeftMotor.spin(vex::directionType::fwd, (Controller.Axis3.value() + Controller.Axis1.value()*2), vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick
    while(1){
      if (Controller.ButtonX.pressing()){
        LeftMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick    
        RightMotor.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick
  } 
      else if (Controller.ButtonY.pressing()){
        LeftMotor.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick    
        RightMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick
      } 

    else{
        LeftMotor.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick    
        RightMotor.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick

    }
  }

}
