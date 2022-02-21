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
// DigitalOutA          digital_out   A               
// LeftMotors           motor_group   1, 2            
// RightMotors          motor_group   11, 12          
// LiftMotors           motor_group   3, 13           
// Controller1          controller                    
// ClampMvmt            motor         4               
// ClampPress           motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "userControl.h"
#include "autonomous.h"
using namespace vex;

competition Competition;
extern brain Brain;

void auton()
{
  Brain.Screen.clearScreen();
  Brain.Screen.print("Running Autonomous A");

  // autonA();
  autonB();
}

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  userControl();
  // auton();
  // Competition.autonomous(auton);
  // Competition.drivercontrol(userControl);
}
