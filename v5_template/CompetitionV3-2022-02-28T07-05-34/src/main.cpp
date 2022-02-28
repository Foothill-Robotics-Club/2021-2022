/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\socce                                            */
/*    Created:      Sun Feb 27 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LeftMotors           motor_group   1, 2
// RightMotors          motor_group   11, 12
// LiftMotors           motor_group   13, 3
// pneum                digital_out   A
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "auton.h"
#include "userControl.h"

using namespace vex;

competition Competition;

void auton()
{
  autonA(true);
  // autonB(false)
}

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Competition.autonomous(auton);
  Competition.drivercontrol(userControl);
  if (!Competition.isFieldControl() && !Competition.isCompetitionSwitch())
  {
    // auton();
    userControl();
  }
}
