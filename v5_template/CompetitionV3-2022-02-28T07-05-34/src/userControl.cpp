#include "vex.h"
#include "math.h"
using namespace vex;

extern controller Controller1;
extern digital_out pneum;
extern brain Brain;
extern motor_group LeftMotors;
extern motor LiftMotor;
extern motor BackLiftLeft;
extern motor BackLiftRight;

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
    group.stop();
  }
}
double calc(double ind){
  double ex = pow(1.0431,abs(ind))-1;
  return ind <0 ? -1*ex : ex;
}
void userControl()
{
  while (1)
  {
    if (Controller1.ButtonL1.pressing())
    {
      pneum.set(false);
    }
    else if (Controller1.ButtonL2.pressing())
    {
      pneum.set(true);
    }
    ConditionalRunning(LiftMotor, Controller1.ButtonR1.pressing(), Controller1.ButtonR2.pressing(), 100);
    ConditionalRunning(BackLiftLeft, Controller1.ButtonX.pressing(), Controller1.ButtonY.pressing(), 50);
    ConditionalRunning(BackLiftRight, Controller1.ButtonX.pressing(), Controller1.ButtonY.pressing(), 100);
    LeftMotors.spin(forward, calc((Controller1.Axis3.value() / 127) * 100), velocityUnits::pct);
    RightMotors.spin(forward, calc((Controller1.Axis2.value() / 127) * 127), velocityUnits::pct);
  }
}