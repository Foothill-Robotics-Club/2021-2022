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
vex::motor LeftMotor = vex::motor(PORT1);
vex::motor RightMotor = vex::motor(PORT11);
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


void Runmotor(vex::motor Motor, int speed, vex::directionType dir,double t)
{
  
  Motor.spinFor(dir,t,vex::timeUnits::msec, speed, vex::velocityUnits::pct);
}


void rotateBotLeft(double t){
  Runmotor(RightMotor,50,reve,t);
  Runmotor(LeftMotor,50,reve,t);
}
void driveForward(double t){
  Runmotor(LeftMotor,50,fowd, t);
  Runmotor(RightMotor,50,reve,t);


}
void driveBackward(double t){
  Runmotor(LeftMotor,50,fowd,t);
  Runmotor(RightMotor,50,reve,t);
}

bool autonomousA(){
  // move forward for 3.5'
  driveForward(3500);
  Runmotor(ClampMotor1, 25,fowd, 1000);
  rotateBotLeft(2000);
  driveBackward(4500);
  rotateBotLeft(1000);
  driveBackward(5500);
  return false;
}
void autonomousB(){

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  bool running =1;
  setup();
  while(!Controller.ButtonL1.pressing()){}
  Brain.Screen.clearScreen();
  while(running){
    running = autonomousA();
    // autonomousB();
  }
  
}
