#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMotorsMotorA = motor(PORT1, ratio18_1, false);
motor LeftMotorsMotorB = motor(PORT2, ratio18_1, false);
motor_group LeftMotors = motor_group(LeftMotorsMotorA, LeftMotorsMotorB);
motor RightMotorsMotorA = motor(PORT11, ratio18_1, true);
motor RightMotorsMotorB = motor(PORT12, ratio18_1, true);
motor_group RightMotors = motor_group(RightMotorsMotorA, RightMotorsMotorB);
motor LiftMotorsMotorA = motor(PORT13, ratio18_1, false);
motor LiftMotorsMotorB = motor(PORT3, ratio18_1, true);
motor_group LiftMotors = motor_group(LiftMotorsMotorA, LiftMotorsMotorB);
digital_out pneum = digital_out(Brain.ThreeWirePort.A);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}