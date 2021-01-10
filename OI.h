/*#####################################################
# Name:			Output Input Header File
#
# Description:	This header file outlines all the
#				output/input devices for the robot.
#				It also outlines any functions needed]
#				for accessing the devices from this
#				class.
#
# Author:		Mitchell Pell
# Version:		1.0
# Date:			06/14/2012 (mm/dd/yyy)
#
# History:		1.0 - MP - First make.
#
######################################################*/
#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Robotmap.h"

class OI {
	
/* OI Constructor */
public:
	OI();
	
/* OI Input Devices and Button Binds */
private:
	//Joystick Device Pointers
	Joystick* 		m_leftJoy;
	Joystick* 		m_rightJoy;
	//Kinect Device Pointers
	KinectStick*	m_leftKinectArm;
	KinectStick*	m_rightKinectArm;
	//Joystick Drive Buttons
	JoystickButton* m_startTankDrive;
	JoystickButton*	m_startArcadeDrive;
	//Kinect Drive Buttons
	JoystickButton* m_startKinectDrive;
	//Camera Control Buttons
	JoystickButton* m_moveCameraLeft;
	JoystickButton* m_moveCameraRight;
	JoystickButton* m_moveCameraDown;
	JoystickButton* m_moveCameraUp;
	JoystickButton* m_centerCamera;
	JoystickButton* m_idleRobot;
	
/*	OI Input Device Value Access */
public:
	//All the functions below simply grab the values from the input
	// device and return them for outside functions to access. Like
	// a command.
	bool 	getCameraLeftPressed(){ return m_moveCameraLeft->Get(); }
	bool 	getCameraRightPressed(){ return m_moveCameraRight->Get(); }
	bool 	getCameraDownPressed(){ return m_moveCameraDown->Get(); }
	bool 	getCameraUpPressed(){ return m_moveCameraUp->Get(); }
	bool 	getCameraCenterPressed(){ return m_centerCamera->Get(); }
	
	float 	getLeftJoyX() { return m_leftJoy->GetX(); }
	float 	getLeftJoyY() { return m_leftJoy->GetY(); }
	float 	getRightJoyX(){ return m_rightJoy->GetX(); }
	float 	getRightJoyY(){ return m_rightJoy->GetY(); }

	float 	getKinectLeftArmX() {return m_leftKinectArm->GetX(); }
	float	getKinectLeftArmY() {return m_leftKinectArm->GetY(); }
	float	getKinectRightArmX(){return m_rightKinectArm->GetX(); }
	float 	getKinectRightArmY(){return m_rightKinectArm->GetY(); }


};
#endif
