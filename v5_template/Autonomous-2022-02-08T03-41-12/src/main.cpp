/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\socce                                            */
/*    Created:      Mon Feb 07 2022                                           */
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

void setup(){
  Brain.Screen.clearLine( 1, black );
  Brain.Screen.setCursor( 1, 1 );
  Brain.Screen.print("Mobility Motors: Port 1 and 2\n");
  Brain.Screen.print("Lift Motors: Port 3 and 4\n");
  Brain.Screen.print("Intake: Port 5\n");
  Brain.Screen.print("ClampMotor: Port 4\n");



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
void clampBot(double t){
  runMotorFor(ClampMotor1, 50, fowd, t);
}

void Runmotor(vex::motor Motor, int speed, vex::directionType dir)
{
  Motor.spin(dir, speed, vex::velocityUnits::pct);
}

bool autonomousA(){
  runMotorFor(ClampMotor1, 100, fowd, 1000);
  Runmotor(LeftMotor,80,fowd);
  Runmotor(RightMotor,80,reve);
  wait(1000,msec);
  Runmotor(LeftMotor, 100, reve);
  Runmotor(RightMotor, 50, fowd);
  wait(500, msec);
  Runmotor(LeftLiftMotor,40,reve);
  Runmotor(RightLiftMotor,40,fwd);
  wait(1000,msec);
  Runmotor(LeftMotor, 100, reve);
  Runmotor(RightMotor, 50, fowd);
  wait(1,sec);
  Runmotor(LeftMotor, 0, reve);
  Runmotor(RightMotor, 0, fowd);
  wait(500, msec);
  runMotorFor(ClampMotor1, 100, reve, 1000);
  wait(1, sec);
  Runmotor(LeftMotor, 100, reve);
  Runmotor(RightMotor, 50, fowd);
  wait(300,msec);
  Runmotor(LeftMotor, 0, reve);
  Runmotor(RightMotor, 0, fowd);
  runMotorFor(ClampMotor1, 100, fowd, 1500);
  wait(1000,msec);
  Runmotor(LeftMotor, 100, fowd);
  Runmotor(RightMotor, 50, reve);
  wait(2.5,sec);
  Runmotor(LeftMotor, 0, fowd);
  Runmotor(RightMotor, 0, reve);
  wait(1, sec);
  return false;
}
bool autonomousB(){
  runMotorFor(ClampMotor1, 100, fowd, 1000);
  Runmotor(LeftMotor,80,fowd);
  Runmotor(RightMotor,80,reve);
  wait(1000,msec);
  Runmotor(LeftMotor, 100, reve);
  Runmotor(RightMotor, 60, fowd);
  wait(500, msec);
  Runmotor(LeftLiftMotor,40,reve);
  Runmotor(RightLiftMotor,40,fwd);
  wait(1000,msec);
  Runmotor(LeftMotor, 100, reve);
  Runmotor(RightMotor, 50, fowd);
  wait(2,sec);
  Runmotor(LeftMotor, 0, reve);
  Runmotor(RightMotor, 0, fowd);
  wait(500, msec);
  runMotorFor(ClampMotor1, 100, reve, 1000);
  wait(1, sec);
  Runmotor(LeftMotor, 100, reve);
  Runmotor(RightMotor, 50, fowd);
  wait(300,msec);
  Runmotor(LeftMotor, 0, reve);
  Runmotor(RightMotor, 0, fowd);
  runMotorFor(ClampMotor1, 100, fowd, 1500);
  wait(1000,msec);
  Runmotor(LeftMotor, 100, fowd);
  Runmotor(RightMotor, 50, reve);
  wait(2.5,sec);
  Runmotor(LeftMotor, 0, fowd);
  Runmotor(RightMotor, 0, reve);
  wait(1, sec);
  return false;

}
// bool autonomousB(){
//   driveForward(3500);
//   rotateBotRight(1000);
//   driveForward(5000);
//   rotateBotRight(1000);
//   driveForward(500);
//   driveForward(4000);
//   rotateBotRight(1000);
//   driveForward(1000);
//   rotateBotRight(1000);
//   driveForward(4000);
//   return false;
// }

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  bool running = 1;
  setup();
  while(!Controller.ButtonL1.pressing()){}
  Brain.Screen.clearScreen();
  while(running){
    running = autonomousA();
    //running = autonomousB();
  }
  
}
