/*#####################################################
# Name:			
# Description:	
#
# Author:		Mitchell Pell
# Version:		1.0
# Date:			05/14/2012 (mm/dd/yyy)
#
# History:		1.0 - MP - 
#
######################################################*/
#include "KinectTankDrive.h"
KinectTankDrive::KinectTankDrive() {
	// Use requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void KinectTankDrive::Initialize() {
	drivetrain->SetDriveMode(Drivetrain::TANK_DRIVE);
}

// Called repeatedly when this Command is scheduled to run
void KinectTankDrive::Execute() {
	

		float leftY = oi->getKinectLeftArmY();
		float rightY = oi->getKinectRightArmY();
		drivetrain->SetInputValues(leftY*(double)2, rightY*(double)2);

}

// Make this return true when this Command no longer needs to run execute()
bool KinectTankDrive::IsFinished() {
	return false;
}


// Called once after isFinished returns true
void KinectTankDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KinectTankDrive::Interrupted() {
}
