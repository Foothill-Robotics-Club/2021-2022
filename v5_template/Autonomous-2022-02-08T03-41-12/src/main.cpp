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
vex::controller Controller;
vex::competition Competition;
vex::motor LeftMotor = vex::motor(PORT1);
vex::motor RightMotor = vex::motor(PORT2);
vex::motor LiftMotor1 = vex::motor(PORT3);
vex::motor LiftMotor2 = vex::motor(PORT4);
vex::directionType fowd = vex::directionType::fwd;
vex::directionType reve = vex::directionType::rev;

vex::motor intake = vex::motor(PORT5);
vex::motor ClampMotor1 = vex::motor(PORT6);


using namespace vex;
void Runmotor(vex::motor Motor, int speed, vex::directionType dir)
{
  Motor.spin(dir, speed, vex::velocityUnits::pct);
}

void rotateBotLeft(){
  Runmotor(RightMotor,50,reve);
  Runmotor(LeftMotor,50,reve);
}
void driveForward(){
  Runmotor(LeftMotor,50,fowd);
  Runmotor(LeftMotor,50,reve);
}
void driveBackward(){
  Runmotor(LeftMotor,50,fowd);
  Runmotor(LeftMotor,50,reve);
}
void autonomousA(){
  // move forward for 3.5'
  driveForward();
  vex::task::sleep(3500);
  // grab base
  Runmotor(ClampMotor1, 25, fowd);
  vex::task::sleep(1000);
  // turn 180 degrees
  rotateBotLeft();
  vex::task::sleep(2000);
  // drive backward for 4.5'
  driveBackward();
  vex::task::sleep(4500);
  // rotate 90 deg
  rotateBotLeft();
  vex::task::sleep(1000);
  // drive back for 1.5'to 2'
  driveBackward();
  vex::task::sleep(1500);
  // drive back for 1.5'to 2'
  driveBackward();
  vex::task::sleep(1500);
  // drive backward 4'
  driveBackward();
  vex::task::sleep(4000);
 
}
void autonomousB(){

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(!Controller.ButtonL1.pressing()){}
  while(1){
    autonomousA();
    // autonomousB();
  }
  
}
