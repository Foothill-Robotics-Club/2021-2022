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
// vex::drivetrain dt = vex::drivetrain(LeftMotor, RightMotor);

bool intakeRunning = false;
bool reves = false;
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
    Runmotor(Motor2, 0, vex::directionType::fwd);
  }
}

void flagCheck(){
  if(Controller.ButtonA.pressing()){
    intakeRunning = true;
    reves = false;
  }
  else if(Controller.ButtonB.pressing()){
      intakeRunning = true;
    reves = true;
  }
  else if(Controller.ButtonX.pressing()){
    intakeRunning = false;
    reves = false;
  }
}
void intakeFunc(){
  if(intakeRunning){
    if(reves){
    Runmotor(intake, 100, vex::directionType::rev);

    }
    else {
    Runmotor(intake, 100, vex::directionType::fwd);
    }
  }else {
    Runmotor(intake, 0, vex::directionType::rev);

  }
}

void userControl()
{
  while(1){
    ConditionalRunning(Controller.ButtonR2.pressing(), Controller.ButtonR1.pressing(), LeftLiftMotor, RightLiftMotor, 25);
  
  // ConditionalRunning(Controller.ButtonA.pressing(), Controller.ButtonB.pressing(), intake, 100);
  mobility();
  flagCheck();
  intakeFunc();
  ConditionalRunning(Controller.ButtonL1.pressing(), Controller.ButtonL2.pressing(), ClampMotor1, 40);
  }
}




void runMotorFor(vex::motor Motor, int speed, vex::directionType dir,double t)
{
  
  Motor.spinFor(dir,t,vex::timeUnits::msec, speed, vex::velocityUnits::rpm);
}

void clampBot(double t){
  runMotorFor(ClampMotor1, 50, reve, t);
}

void rotateBotLeft(double t){
  runMotorFor(RightMotor,50,reve,t);
  runMotorFor(LeftMotor,50,reve,t);
}
void rotateBotRight(double t){
  runMotorFor(LeftMotor,50,reve,t);
  runMotorFor(RightMotor,50,reve,t);
}
void driveBackward(double t){
  runMotorFor(LeftMotor,100,fowd, t);
  runMotorFor(RightMotor,100,reve,t);


}
void driveForward(double t){
  runMotorFor(LeftMotor,100,fowd,t);
  runMotorFor(RightMotor,100,reve,t);
}

void autonomousA(){
  
  Runmotor(LeftMotor, 100, reve);
  Runmotor(RightMotor, 50, fowd);
  wait(2,sec);
  Runmotor(LeftMotor, 0, reve);
  Runmotor(RightMotor, 0, fowd);
  wait(500,msec);
  Runmotor(LeftLiftMotor,50,fowd);
  Runmotor(RightLiftMotor,50,reve);
  wait(750,msec);
  runMotorFor(ClampMotor1, 50, reve, 1000);
  runMotorFor(ClampMotor1, 50, fowd, 1000);
  wait(500,msec);
  Runmotor(LeftMotor, 100, fowd);
  Runmotor(RightMotor, 50, reve);
  wait(2,sec);
  Runmotor(LeftMotor, 0, fowd);
  Runmotor(RightMotor, 0, reve);
  wait(1, sec);

  // runMotorFor(ClampMotor1, 25,fowd, 1000);
  // rotateBotLeft(2000);
  // rotateBotLeft(1000);
  // driveBackward(4000);
  // return false;
}
void autonomousB(){
  driveForward(3500);
  rotateBotRight(1000);
  driveForward(5000);
  rotateBotRight(1000);
  driveForward(500);
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
