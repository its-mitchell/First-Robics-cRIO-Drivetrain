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
#include "JoystickArcadeDrive.h"

JoystickArcadeDrive::JoystickArcadeDrive() {
	// Use requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void JoystickArcadeDrive::Initialize() {
	drivetrain->SetDriveMode(Drivetrain::ARCADE_DRIVE);
}

// Called repeatedly when this Command is scheduled to run
void JoystickArcadeDrive::Execute() {
		float y = oi->getLeftJoyY();
		float x = oi->getLeftJoyX();
	drivetrain->SetInputValues(x, y);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickArcadeDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickArcadeDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickArcadeDrive::Interrupted() {
}
