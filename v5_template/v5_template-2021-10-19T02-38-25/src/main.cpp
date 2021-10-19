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

void intake(){

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  LeftMotor.spin(vex::directionType::fwd, (Controller.Axis3.value() + Controller.Axis1.value()*2), vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick
  
}
