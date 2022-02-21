#include "vex.h"

using namespace vex;

extern motor_group LeftMotors;
extern motor_group RightMotors;
extern motor_group LiftMotors;
extern digital_out DigitalOutA;
extern motor ClampMvmt;

// drivetrain dt = drivetrain(LeftMotors, RightMotors);
void mobility(double duration, double speed, directionType dir)
{
  LeftMotors.spin(dir, speed, velocityUnits::pct);
  RightMotors.spin(dir, speed, velocityUnits::pct);
  wait(duration, msec);
  RightMotors.stop();
  LeftMotors.stop();
}

void mobility(double duration, double speedLeft, double speedRight, directionType dirLeft, directionType dirRight)
{
  LeftMotors.spin(dirLeft, speedLeft, velocityUnits::pct);
  RightMotors.spin(dirRight, speedRight, velocityUnits::pct);
  wait(duration, msec);
  LeftMotors.stop();
  RightMotors.stop();
}

void lift(bool up, double speed, double duration)
{
  LiftMotors.spin(up ? forward : reverse, speed, velocityUnits::pct);
  wait(duration, msec);
}

void turnLeft(double duration)
{
  mobility(duration, 50, 50, reverse, forward);
}
void turnRight(double duration)
{
  mobility(duration, 50, 50, forward, reverse);
}

void autonA()
{
  DigitalOutA.set(false);
  mobility(1700, 100, forward);
  wait(500, msec);
  DigitalOutA.set(true);
  mobility(400, 100, forward);
  wait(500, msec);
  DigitalOutA.set(false);
  mobility(2200, 100, reverse);
  turnLeft(2500);
}

void autonB()
{
  DigitalOutA.set(false);
  mobility(1900, 100, forward);
  wait(500, msec);
  DigitalOutA.set(true);
  mobility(400, 100, forward);
  wait(500, msec);
  DigitalOutA.set(false);
  mobility(2200, 100, reverse);
  turnRight(2500);
}