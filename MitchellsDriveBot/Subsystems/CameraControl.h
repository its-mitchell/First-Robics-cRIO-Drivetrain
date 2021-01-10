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
#ifndef CAMERA_CONTROL_H
#define CAMERA_CONTROL_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *	
 *	Subsystem: 		Camera Control
 *	
 *	Description:	This subsystem controlls the camera
 *
 * @author Mitchell Pell
 */
class CameraControl: public Subsystem {
private:
	//Members for controlling the servos
	//Below are the Camera classes
	Servo* cameraRotate;	//Rotate / Yaw
	Servo* cameraTilt;		//Tilt	 / Pitch
	//Below are mapped values to track the cameras
	// rotation
	float rotateAngle;
	float tiltAngle;
public:
	CameraControl();
	void InitDefaultCommand();
	//Created interfaces to control the camera
	void centerCamera();
	void updateCameraLocation();
	void tiltCamera(float angle);
	void rotateCamera(float angle);
};

#endif
