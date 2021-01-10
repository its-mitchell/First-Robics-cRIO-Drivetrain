/*#####################################################
# Name:			
# Description:	
#
# Author:		Mitchell Pell
# Version:		1.0
# Date:			06/14/2012 (mm/dd/yyy)
#
# History:		1.0 - MP - First make.
#
######################################################*/
#include "JoystickTankDrive.h"

JoystickTankDrive::JoystickTankDrive() {
	// Use requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void JoystickTankDrive::Initialize() {
	drivetrain->SetDriveMode(Drivetrain::TANK_DRIVE);
}

// Called repeatedly when this Command is scheduled to run
void JoystickTankDrive::Execute() {
		float leftY = oi->getLeftJoyY();
		float rightY = oi->getRightJoyY();
	drivetrain->SetInputValues(leftY, rightY);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickTankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickTankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickTankDrive::Interrupted() {
}
