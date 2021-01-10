/*#####################################################
# Name:			Output Input Code File
#
# Description:	This code file contains the header
#				files constructor, which defines the
#				inputs and binds them to commands.
#				
#
# Author:		Mitchell Pell
# Version:		1.0
# Date:			06/14/2012 (mm/dd/yyy)
#
# History:		1.0 - MP - First make.
#
######################################################*/
#include "OI.h"
#include "Commands/JoystickTankDrive.h"		//Needed to bind the Joystick Tank Drive Command
#include "Commands/JoystickArcadeDrive.h"	//Needed to bind the Joystick Arcade Drive Command
#include "Commands/KinectTankDrive.h"		//Needed to bind the Kinect Tank Drive Command
#include "Commands/KinectSafeStart.h"		//Needed to bind the Kinect Safe Start Command
#include "Commands/IdleBot.h"				//Needed to bind the Idle Robot Command
#include "Robotmap.h"						//Needed for global constants

//This is the OIs constructor. It will create all the input devices and binds
OI::OI() {

	//ASSIGN JOYSTICKS
	m_leftJoy = new Joystick(JOYSTICK_LEFT);
	m_rightJoy = new Joystick(JOYSTICK_RIGHT);
	//ASSIGN KINECT JOYSTICK ARMS
	m_leftKinectArm = new KinectStick(1);
	m_rightKinectArm = new KinectStick(2);
	//Kinect Drive Buttons
	m_startKinectDrive = new JoystickButton(m_leftJoy, START_KINECT_TANK_DRIVE);
	//IF SMART DASHBOARD ENABLED, SETUP INPUT DATA SENDING
	//Joystick Drive Buttons
	m_startTankDrive = new JoystickButton(m_leftJoy, START_JOY_TANK_DRIVE);
	m_startArcadeDrive = new JoystickButton(m_leftJoy, START_JOY_ARCADE_DRIVE);
	//Camera Control Buttons
	m_moveCameraLeft = new JoystickButton(m_leftJoy, CAMERA_LEFT);
	m_moveCameraRight = new JoystickButton(m_leftJoy, CAMERA_RIGHT);
	m_moveCameraDown = new JoystickButton(m_leftJoy, CAMERA_DOWN);
	m_moveCameraUp = new JoystickButton(m_leftJoy, CAMERA_UP);
	m_centerCamera = new JoystickButton(m_leftJoy, CAMERA_CENTER);
	m_idleRobot = new JoystickButton(m_leftJoy, START_IDLE_BOT);
	
	//Bind the buttons to commands
	//--------------------------------------------------
	
	//Joystick Drive Buttons
	m_startTankDrive->WhenPressed(new JoystickTankDrive() );
	m_startArcadeDrive->WhenPressed(new JoystickArcadeDrive() );
	//Idle Robot
	m_idleRobot->WhenPressed(new IdleBot() );
	//Kinect Drive Buttons
	m_startKinectDrive->WhenPressed(new KinectSafeStart() );
}
