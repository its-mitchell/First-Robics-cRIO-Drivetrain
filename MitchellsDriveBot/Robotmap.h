/*#####################################################
# Name:			Robotmap header file
# Description:	This file contains all the global
#				constants defined for the robot. Like
#				pin numbers.
#
# Author:		Mitchell Pell
# Version:		1.0
# Date:			06/14/2012 (mm/dd/yyy)
#
# History:		1.0 - MP - First make.
#
######################################################*/
#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//Do not change the SmartDashboard values below;
// change SD_LEVEL to match one of the three.
#define SD_DISABLED						0
#define SD_ENABLED						1
#define SD_DEBUG						2

// You may edit the values below this point, but try
// and not break anything.
//=======================================================
//		DESCRIPTION					|  NUMBER
//----------------------------------+--------------------
//-> Compile Properties
#define KINECT_ENABLED					0
#define SD_LEVEL 						0
//-> Jaguar Pin Locations
#define DRIVE_MOTOR_LEFT 				1
#define DRIVE_MOTOR_RIGHT				2
//-> Camera Pin Locations	
#define CAMERA_PITCH					4
#define CAMERA_YAW						3
//-> Camera Servo Pin Locations
#define CAMERA_LEFT						4
#define CAMERA_RIGHT					5
#define CAMERA_DOWN						2
#define CAMERA_UP						3
#define CAMERA_CENTER					1
//-> Joystick Numbers
#define JOYSTICK_LEFT 					2
#define JOYSTICK_RIGHT 					1
//-> Left Joystick Button Mapping
#define START_JOY_TANK_DRIVE			6
#define START_JOY_ARCADE_DRIVE			7
#define START_IDLE_BOT					8
#define START_KINECT_TANK_DRIVE 		11
//-------------------------------------------------------

//Drivtrain Subsystem Constants
static const double MAX_VAL_CHANGE = 0.5;	//Input value ( 0 to 1 )
static const double MAX_INPUT_DELAY = 2.0; //Seconds
//Kinect Safe Start Command Constants
static const float SAFE_START_BOUNDS = 0.0125f; //

//End of File
#endif
