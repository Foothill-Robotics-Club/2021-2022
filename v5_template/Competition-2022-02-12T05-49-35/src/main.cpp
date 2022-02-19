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

vex::motor LeftBackMotor = vex::motor(PORT1);
vex::motor RightBackMotor = vex::motor(PORT11);
vex::motor LeftFrontMotor = vex::motor(PORT2);
vex::motor RightFrontMotor = vex::motor(PORT12);
vex::motor LeftLiftMotor = vex::motor(PORT3);
vex::motor RightLiftMotor = vex::motor(PORT13);
vex::directionType fowd = vex::directionType::fwd;
vex::directionType reve = vex::directionType::rev;
digital_out dig1 = digital_out(Brain.ThreeWirePort.H);

bool intakeRunning = false;
bool reves = false;
void mobility()
{
  LeftBackMotor.spin(vex::directionType::rev, (Controller.Axis3.value()), vex::velocityUnits::pct);  // left motor will spin forward and change direction according to input from the right stick
  LeftFrontMotor.spin(vex::directionType::rev, (Controller.Axis3.value()), vex::velocityUnits::pct);  // left motor will spin forward and change direction according to input from the right stick
  RightBackMotor.spin(vex::directionType::fwd, (Controller.Axis2.value()), vex::velocityUnits::pct); // right motor will spin forward and change direction according to input from the left stick
  RightFrontMotor.spin(vex::directionType::fwd, (Controller.Axis2.value()), vex::velocityUnits::pct);  // left motor will spin forward and change direction according to input from the right stick
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

// void flagCheck(){
//   if(Controller.ButtonA.pressing()){
//     // intakeRunning = true;
//     reves = false;
//   }
//   else if(Controller.ButtonB.pressing()){
//     // intakeRunning = true;
//     reves = true;
//   }
//   else if(Controller.ButtonX.pressing()){
//     // intakeRunning = false;
//     reves = false;
//   }
// }
// void intakeFunc(){
//   if(intakeRunning){
//     if(reves){
//     Runmotor(intake, 100, vex::directionType::rev);

//     }
//     else {
//     Runmotor(intake, 100, vex::directionType::fwd);
//     }
//   }else {
//     Runmotor(intake, 0, vex::directionType::rev);

//   }
// }

void userControl()
{
  while(1){
    ConditionalRunning(Controller.ButtonR2.pressing(), Controller.ButtonR1.pressing(), LeftLiftMotor, RightLiftMotor, 25);
  // ConditionalRunning(Controller.ButtonA.pressing(), Controller.ButtonB.pressing(), intake, 100);
  mobility();
  // flagCheck();
  // intakeFunc();
  }
}




void runMotorFor(vex::motor Motor, int speed, vex::directionType dir,double t)
{
  
  Motor.spinFor(dir,t,vex::timeUnits::msec, speed, vex::velocityUnits::rpm);
}

// void clampBot(double t){
//   runMotorFor(ClampMotor1, 50, reve, t);
// }

void rotateBotLeft(double t){
  runMotorFor(RightBackMotor,50,reve,t);
  runMotorFor(LeftBackMotor,50,reve,t);
  runMotorFor(RightFrontMotor,50,reve,t);
  runMotorFor(LeftFrontMotor,50,reve,t);
}
void rotateBotRight(double t){
  runMotorFor(RightBackMotor,50,fowd,t);
  runMotorFor(LeftBackMotor,50,fowd,t);
  runMotorFor(RightFrontMotor,50,fowd,t);
  runMotorFor(LeftFrontMotor,50,fowd,t);
}
void driveBackward(double t){
  runMotorFor(RightBackMotor,50,fowd,t);
  runMotorFor(LeftBackMotor,50,reve,t);
  runMotorFor(RightFrontMotor,50,fowd,t);
  runMotorFor(LeftFrontMotor,50,reve,t);
}
void driveForward(double t){
  runMotorFor(RightBackMotor,50,reve,t);
  runMotorFor(LeftBackMotor,50,fowd,t);
  runMotorFor(RightFrontMotor,50,reve,t);
  runMotorFor(LeftFrontMotor,50,fowd,t);
}
bool autonomousA() {
  runMotorFor(LeftBackMotor, 100, fowd, 1500);
  runMotorFor(RightBackMotor, 90, reve, 1500);
  runMotorFor(LeftFrontMotor, 100, fowd, 1500);
  runMotorFor(RightFrontMotor, 90, reve, 1500);
  Runmotor(LeftLiftMotor,80,reve);
  Runmotor(RightLiftMotor,80,fowd);
  wait(300, msec);
  Runmotor(LeftLiftMotor,80,fowd);
  Runmotor(RightLiftMotor,80,reve);
  wait(300, msec);
  driveForward(400);
  wait(300, msec);
  runMotorFor(LeftBackMotor, 100, reve, 1500);
  runMotorFor(RightBackMotor, 90, fowd, 1500);
  runMotorFor(LeftFrontMotor, 100, reve, 1500);
  runMotorFor(RightFrontMotor, 90, fowd, 1500);
  rotateBotRight(400);
  return false;
}  
bool autonomousB(){
  driveForward(1000);
  Runmotor(LeftLiftMotor,80,reve);
  Runmotor(RightLiftMotor,80,fowd);
  wait(300, msec);
  driveForward(400);
  Runmotor(LeftLiftMotor,80,fowd);
  Runmotor(RightLiftMotor,80,reve);
  wait(300, msec);
  return false;
}
bool autonomousC() {
  if (Controller.ButtonL1.pressing()) {
      dig1.set(true);
  }
  else {
      dig1.set(false);
  }
  return false;
}
void autonomous(){
  // autonomousA();
  // autonomousB();
  autonomousC();
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Competition.drivercontrol(userControl);
  Competition.autonomous(autonomous);
  vex::controller master(vex::controllerType::primary);
  digital_out dig1 = digital_out(Brain.ThreeWirePort.A);

  while(1) {
    if( master.ButtonL1.pressing() ) {
      dig1.set( false );
    }
    else {
      dig1.set( true );
    }
    this_thread::sleep_for(10);
  }
}
