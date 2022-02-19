/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\socce                                            */
/*    Created:      Mon Feb 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// DigitalOutA          digital_out   A               
// DigitalOutB          digital_out   B               
// LeftMotors           motor_group   1, 2            
// RightMotors          motor_group   11, 12          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "userControl.h"
#include "autonomous.h"
using namespace vex;

competition Competition;
extern brain Brain;

void auton(){
  Brain.Screen.clearScreen();
  Brain.Screen.print("Running Autonomous A")
  autonA();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  userControl();
  // Competition.autonomous(auton);
  // Competition.drivercontrol(userControl);
  
}

