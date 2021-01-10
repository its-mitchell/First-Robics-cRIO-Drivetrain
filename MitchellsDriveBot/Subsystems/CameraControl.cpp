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
#include "CameraControl.h"
#include "../Robotmap.h"
#include "../Commands/ControlCamera.h"

/*
 * Camera Subsystem constructor
 */
CameraControl::CameraControl() : Subsystem("CameraControl"){
	cameraRotate = new Servo(CAMERA_YAW);
	cameraTilt = new Servo(CAMERA_PITCH);
	rotateAngle = 0;
	tiltAngle = 0;
}
/*
 * Default command to run when one is not
 * already runing.
 */
void CameraControl::InitDefaultCommand(){
	SetDefaultCommand(new ControlCamera());
}
/*
 * Centers the cameras targer angles;
 */
void CameraControl::centerCamera(){
	rotateAngle = 0;
	tiltAngle = 0;
	
}
/*
 * Updates the cameras servos to the set location
 */
void CameraControl::updateCameraLocation(){
	cameraTilt->Set((tiltAngle + 1.0)/2);
	cameraRotate->Set((rotateAngle + 1.0)/2);
}
/*
 * Updates the tilt servos target angle
 */
void CameraControl::tiltCamera(float angle){
	tiltAngle += angle;
}
/*
 * Updates the rotate cameras target angle
 */
void CameraControl::rotateCamera(float angle){
	rotateAngle += angle;
}
