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
#include "IdleBot.h"

IdleBot::IdleBot() {
	// Use requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void IdleBot::Initialize() {
	drivetrain->SetDriveMode(Drivetrain::IDLE);
}

// Make this return true when this Command no longer needs to run execute()
bool IdleBot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IdleBot::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IdleBot::Interrupted() {
}
