/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lym20                                            */
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
vex::motor LeftMotor = vex::motor(PORT1);
vex::motor RightMotor = vex::motor(PORT2);
vex::motor LiftMotor1 = vex::motor(PORT3);
vex::motor LiftMotor2 = vex::motor(PORT4);
vex::motor RingMotor1 = vex::motor(PORT5);
vex::motor ClampMotor1 = vex::motor(PORT6);





void intake(){

}

void userControl(){
  LeftMotor.spin(vex::directionType::fwd, (Controller.Axis3.value() + Controller.Axis1.value()*2), vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick
  RightMotor.spin(vex::directionType::fwd, (Controller.Axis3.value() - Controller.Axis1.value()*2), vex::velocityUnits::pct);//right motor will spin forward and change direction according to input from the left stick

}
void Runmotor(vex::motor Motor, int speed,vex::directionType  dir){
  Motor.spin(dir,speed, vex::velocityUnits::pct);

}

void ConditionalRunning(bool condition,bool other, vex::motor Motor,int speed){
  if(condition){
    Runmotor(Motor,speed, vex::directionType::fwd);
  }
  else if(other){
    Runmotor(Motor,speed, vex::directionType::rev);
  }
  else {
    Runmotor(Motor,0, vex::directionType::fwd);

  }
}
void ConditionalRunning(bool condition,bool other, vex::motor Motor1,vex::motor Motor2,int speed){
  if(condition){
    Runmotor(Motor1,speed, vex::directionType::fwd);
    Runmotor(Motor2,speed, vex::directionType::rev);

  }
  else if(other){
    Runmotor(Motor1,speed, vex::directionType::rev);
    Runmotor(Motor2,speed, vex::directionType::fwd);

  }
  else {
    Runmotor(Motor1,0, vex::directionType::fwd);
    Runmotor(Motor1,0, vex::directionType::fwd);


  }
}




void clamp(){
  

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  // bool test = true;

  vexcodeInit();

  //LeftMotor.spin(vex::directionType::fwd, (Controller.Axis3.value() + Controller.Axis1.value()*2), vex::velocityUnits::pct);//left motor will spin forward and change direction according to input from the right stick
    while(1){
      ConditionalRunning(Controller.ButtonX.pressing(),Controller.ButtonY.pressing(),LiftMotor1,LiftMotor2, 25);
      ConditionalRunning(Controller.ButtonA.pressing(),Controller.ButtonB.pressing(),RingMotor1,50);

      userControl();
      clamp();
      


    
  }

}
