using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern digital_out DigitalOutA;
extern digital_out DigitalOutB;
extern motor_group LeftMotors;
extern motor_group RightMotors;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );