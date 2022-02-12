/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\socce                                            */
/*    Created:      Fri Feb 11 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

vex::controller Controller;
vex::competition Competition;

vex::motor LeftMotor = vex::motor(PORT11);
vex::motor RightMotor = vex::motor(PORT1);
vex::motor LeftLiftMotor = vex::motor(PORT2);
vex::motor RightLiftMotor = vex::motor(PORT12);
vex::motor intake = vex::motor(PORT13);
vex::motor ClampMotor1 = vex::motor(PORT3);
vex::directionType fowd = vex::directionType::fwd;
vex::directionType reve = vex::directionType::rev;

void mobility()
{
  LeftMotor.spin(vex::directionType::rev, (Controller.Axis3.value()*1.05), vex::velocityUnits::pct);  // left motor will spin forward and change direction according to input from the right stick
  RightMotor.spin(vex::directionType::fwd, (Controller.Axis2.value()), vex::velocityUnits::pct); // right motor will spin forward and change direction according to input from the left stick
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
  while(1){
    ConditionalRunning(Controller.ButtonX.pressing(), Controller.ButtonY.pressing(), LeftLiftMotor, RightLiftMotor, 25);
    ConditionalRunning(Controller.ButtonA.pressing(), Controller.ButtonB.pressing(), intake, 70);
    mobility();

    ConditionalRunning(Controller.ButtonL1.pressing(), Controller.ButtonL2.pressing(), ClampMotor1, 25);
  }
}



void runMotorFor(vex::motor Motor, int speed, vex::directionType dir,double t)
{
  
  Motor.spinFor(dir,t,vex::timeUnits::msec, speed, vex::velocityUnits::rpm);
}


void rotateBotLeft(double t){
  runMotorFor(RightMotor,50,reve,t);
  runMotorFor(LeftMotor,50,reve,t);
}
void rotateBotRight(double t){
  runMotorFor(LeftMotor,50,reve,t);
  runMotorFor(RightMotor,50,reve,t);
}
void driveForward(double t){
  runMotorFor(LeftMotor,50,fowd, t);
  runMotorFor(RightMotor,50,reve,t);


}
void driveBackward(double t){
  runMotorFor(LeftMotor,50,fowd,t);
  runMotorFor(RightMotor,50,reve,t);
}

void autonomousA(){
  driveForward(3500);
  // runMotorFor(ClampMotor1, 25,fowd, 1000);
  rotateBotLeft(2000);
  driveBackward(4500);
  rotateBotLeft(1000);
  driveBackward(5500);
  // return false;
}
void autonomousB(){
  driveForward(3500);
  rotateBotRight(1000);
  driveForward(5000);
  rotateBotRight(1000);
  driveForward(500);
  driveForward(4000);
  rotateBotRight(1000);
  driveForward(1000);
  rotateBotRight(1000);
  driveForward(4000);
  // return false;
}

void autonomous(){
  autonomousA();
  // autonomousB();
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Competition.drivercontrol(userControl);
  Competition.autonomous(autonomous);
  
  
}
