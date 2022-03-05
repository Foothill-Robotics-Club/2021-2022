#include "vex.h"
#include "math.h"
using namespace vex;

extern controller Controller1;
extern digital_out pneum;
extern brain Brain;
extern motor_group LeftMotors;
extern motor LiftMotor;

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

void userControl()
{
  while (1)
  {
    if (Controller1.ButtonX.pressing())
    {
      pneum.set(false);
    }
    else if (Controller1.ButtonY.pressing())
    {
      pneum.set(true);
    }
    ConditionalRunning(LiftMotor, Controller1.ButtonA.pressing(), Controller1.ButtonB.pressing(), 127);
    LeftMotors.spin(forward, (Controller1.Axis3.value() / 127) * 100, velocityUnits::pct);
    RightMotors.spin(reverse, (Controller1.Axis2.value() / 127) * 127, velocityUnits::pct);
  }
}