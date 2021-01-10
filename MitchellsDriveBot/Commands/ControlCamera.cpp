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
#include "ControlCamera.h"

ControlCamera::ControlCamera() {
	//This registeres that this command requires the cameraSystem
	//and stops any commands using this system when activated.
	Requires(cameraControl);

}


// Called just before this Command runs the first time
void ControlCamera::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ControlCamera::Execute() {
	if ( oi->getCameraCenterPressed())
	{
		cameraControl->centerCamera();
	}else
	{
		//Check Left or Right to prevent moving Left and Right
		if ( oi->getCameraLeftPressed()){
			cameraControl->rotateCamera(-0.025);
		} else if ( oi->getCameraRightPressed()){
			cameraControl->rotateCamera(0.025);
		}
		//Check Down or Up to prevent moving Down and Up
		if ( oi->getCameraUpPressed()){
			cameraControl->tiltCamera(-0.025);
		} else if ( oi->getCameraDownPressed()){
			cameraControl->tiltCamera(0.025);
		}
	}
	//Update Camera Location
	cameraControl->updateCameraLocation();
}

// Make this return true when this Command no longer needs to run execute()
bool ControlCamera::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlCamera::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlCamera::Interrupted() {
	
}
