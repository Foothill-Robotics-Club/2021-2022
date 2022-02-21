#include "vex.h"

using namespace vex;

extern motor_group LeftMotors;
extern motor_group RightMotors;
extern motor_group LiftMotors;
extern digital_out DigitalOutA;
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
  DigitalOutA.set(true);
  // DigitalOutA.set(false);
  mobility(750, 100, forward);
  wait(500, msec);
  DigitalOutA.set(false);
  mobility(750, 100, reverse);

  // lift(true, 80, 300);
  // lift(false, 80, 300);
  // mobility(300, 100, forward);

  // mobility(1500, 100, reverse);
  // turnRight(400);
}

void autonB()
{
  DigitalOutA.set(true);
  mobility(500, 100, forward);
  // wait(2,sec);
  turnLeft(700);
  // wait(2,sec);

  mobility(2000, 100, forward);
  // wait(2,sec);

  DigitalOutA.set(false);
  mobility(2000, 100, reverse);

  // mobility(500,100,reverse);
  // turnLeft(700);
  // mobility(2000,100,reverse);

  // mobility(2000, 100, forward);
  // lift(true, 80, 300);
  // mobility(400, 100, forward);
  // lift(false, 80, 300);
}