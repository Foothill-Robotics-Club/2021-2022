#include "vex.h"
#include "math.h"

extern controller Controller1;
extern digital_out DigitalOutA;
extern brain Brain;
extern motor_group LeftMotors;
extern motor_group LiftMotors;
extern motor ClampMvmt;

void ConditionalRunning(motor_group group, bool condition, bool othercondition, double speed)
{
  if (condition)
  {
    group.spin(forward, speed, velocityUnits::pct);
  }
  else if (othercondition)
  {
    group.spin(reverse, speed, velocityUnits::pct);
  }
  else
  {
    group.spin(forward, 0, velocityUnits::pct);
  }
}

double calc(double input){
  double out = pow(1.047, abs(input)) - 1;
  if(input<0){
    return -1*out;
  }else{
    return out; 
  }
}

// User control function
void userControl()
{
  Brain.Screen.print("User Control");

  while (true)
  {
    Brain.Screen.clearScreen();
    if (Controller1.ButtonL1.pressing())
    {
      DigitalOutA.set(true);
    }

    else if (Controller1.ButtonL2.pressing())
    {
      DigitalOutA.set(false);
    }
    ConditionalRunning(LiftMotors, Controller1.ButtonR1.pressing(), Controller1.ButtonR2.pressing(), 50);
    LeftMotors.spin(forward, calc(Controller1.Axis3.value()), velocityUnits::pct);
    RightMotors.spin(forward, calc(Controller1.Axis2.value()), velocityUnits::pct);
    ConditionalRunning(ClampMvmt, Controller1.ButtonY.pressing(), Controller1.ButtonX.pressing(), 20);
    wait(20, msec);
  }
}