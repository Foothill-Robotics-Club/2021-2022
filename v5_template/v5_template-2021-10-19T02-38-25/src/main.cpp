/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\seant                                            */
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
vex::motor LeftMotor = vex::motor(PORT2);
vex::motor RightMotor = vex::motor(PORT3);
vex::motor LiftMotor1 = vex::motor(PORT12);
vex::motor LiftMotor2 = vex::motor(PORT13);

vex::motor intake = vex::motor(PORT11);
vex::motor ClampMotor1 = vex::motor(PORT1);

void mobility()
{
  LeftMotor.spin(vex::directionType::rev, (Controller.Axis3.value() * 2), vex::velocityUnits::pct);  // left motor will spin forward and change direction according to input from the right stick
  RightMotor.spin(vex::directionType::fwd, (Controller.Axis2.value() * 2), vex::velocityUnits::pct); // right motor will spin forward and change direction according to input from the left stick
}
void Runmotor(vex::motor Motor, int speed, vex::directionType dir)
{
  Motor.spin(dir, speed, vex::velocityUnits::pct);
}

void ConditionalRunning(bool condition, bool other, vex::motor Motor, int speed)
{
  if (condition)
  {
    Runmotor(Motor, speed, vex::directionType::fwd);
  }
  else if (other)
  {
    Runmotor(Motor, speed, vex::directionType::rev);
  }
  else
  {
    Runmotor(Motor, 0, vex::directionType::fwd);
  }
}
void ConditionalRunning(bool condition, bool other, vex::motor Motor1, vex::motor Motor2, int speed)
{
  if (condition)
  {
    Runmotor(Motor1, speed, vex::directionType::fwd);
    Runmotor(Motor2, speed, vex::directionType::rev);
  }
  else if (other)
  {
    Runmotor(Motor1, speed, vex::directionType::rev);
    Runmotor(Motor2, speed, vex::directionType::fwd);
  }
  else
  {
    Runmotor(Motor1, 0, vex::directionType::fwd);
    Runmotor(Motor1, 0, vex::directionType::fwd);
  }
}



void userControl()
{

  ConditionalRunning(Controller.ButtonX.pressing(), Controller.ButtonY.pressing(), LiftMotor1, LiftMotor2, 25);
  ConditionalRunning(Controller.ButtonA.pressing(), Controller.ButtonB.pressing(), intake, 50);
  mobility();
  ConditionalRunning(Controller.ButtonR2.pressing(),Controller.ButtonL2.pressing(),ClampMotor1,50);
}

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  // bool test = true;

  vexcodeInit();

  while (1)
  {
    userControl();
  }
  // autonomousA();
  // LeftMotor.spin(vex::directionType::fwd, (Controller.Axis3.value() + Controller.Axis1.value()*2), vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick
}
