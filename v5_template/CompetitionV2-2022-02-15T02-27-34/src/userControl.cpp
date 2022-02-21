#include "vex.h"

extern controller Controller1;
extern digital_out DigitalOutA;
// extern digital_out DigitalOutB;
extern brain Brain;
extern motor_group LeftMotors;
// extern motor LeftMotorsA;
// extern motor LeftMotorsB;
// extern motor RightMotorsA;
// extern motor RightMotorsB;
extern motor_group LiftMotors;

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
      // DigitalOutB.set(true);
    }

    else if (Controller1.ButtonL2.pressing())
    {
      DigitalOutA.set(false);
      // DigitalOutB.set(false);
    }
    ConditionalRunning(LiftMotors, Controller1.ButtonR1.pressing(), Controller1.ButtonR2.pressing(), 50);
    LeftMotors.spin(forward, Controller1.Axis3.value(), velocityUnits::pct);
    RightMotors.spin(forward, Controller1.Axis2.value(), velocityUnits::pct);
    ConditionalRunning(ClampMvmt, Controller1.ButtonX.pressing(), Controller1.ButtonY.pressing(), 50);
    ConditionalRunning(ClampPress, Controller1.ButtonA.pressing(), Controller1.ButtonB.pressing(), 50);
    // Brain.Screen.print(RightMotorsA.velocity(velocityUnits::pct));

    wait(20, msec);
  }
}