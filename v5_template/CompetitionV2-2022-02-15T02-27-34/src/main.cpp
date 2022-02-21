/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\adivs                                            */
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
  autonA();
  // Brain.Screen.print("Running Autonomous B");
  // autonB();
}

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Runs User Control
  // userControl();

  // Runs Autonomous Code (Check auton function for which auton we're running!)
  // auton();

  // Competition Format
  Competition.autonomous(auton);
  Competition.drivercontrol(userControl);
}
