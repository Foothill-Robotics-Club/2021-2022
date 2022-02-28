using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor_group LeftMotors;
extern motor_group RightMotors;
extern motor_group LiftMotors;
extern digital_out pneum;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );