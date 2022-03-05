#include "vex.h"
using namespace vex;
extern motor_group LeftMotors;
extern motor_group RightMotors;
extern motor_group LiftMotors;
extern digital_out DigitalOutA;
extern digital_out pneum;

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

void autonA() {
  pneum.set(true);
  mobility(2000,  100, forward);
  pneum.set(false);
  mobility(200, 100, forward);
  pneum.set(true);
  turnLeft(1000);
  mobility(1500, 100, forward);
  lift(1, 100, 500);
  mobility(300, 100, forward);
  lift(0, 100, 500);
}

void autonB() {
  
}
