#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMotorsMotorA = motor(PORT1, ratio18_1, true);
motor LeftMotorsMotorB = motor(PORT8, ratio18_1, true);
motor_group LeftMotors = motor_group(LeftMotorsMotorA, LeftMotorsMotorB);
motor RightMotorsMotorA = motor(PORT11, ratio18_1, false);
motor RightMotorsMotorB = motor(PORT12, ratio18_1, false);
motor_group RightMotors = motor_group(RightMotorsMotorA, RightMotorsMotorB);
digital_out pneum = digital_out(Brain.ThreeWirePort.H);
motor BackLiftLeft = motor(PORT4, ratio18_1, false);
motor BackLiftRight = motor(PORT13, ratio36_1, true);
motor LiftMotor = motor(PORT18, ratio36_1, false);

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