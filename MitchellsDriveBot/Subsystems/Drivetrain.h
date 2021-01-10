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
#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


/**
 *	
 *	Subsystem: 		Drivetrain
 *	
 *	Description:	This subsystem controlls the drivetrain :)
 *	
 *	Features:		Safe input checking - If the input exceeds
 *					a certain value the subsystem will start
 *					the IdleBot command stopping it.
 *					
 *					Idle checking - If input is not changed for x
 *					seconds the subsystem will start
 *					the IdleBot command stopping it.
 *
 * @author Mitchell Pell
 */
class Drivetrain: public Subsystem {
public:

	//The statics below are located in Robotmap.h
	//static const double MAX_VAL_CHANGE = 0.5;	//Input value ( 0 to 1 )
	//static const double MAX_INPUT_DELAY = 2.0; //Seconds
	
	//This enum allows for easy switching between drive modes
	enum DriveMode
	{
		IDLE = 0,
		TANK_DRIVE,
		ARCADE_DRIVE
	};
private:
	DriveMode driveMode;	//The current drivemode
	Timer*	timer;			//Timer for idle input checking
	double* inputValues;	//Input array for comparing with old
							//for large value jumps
	//Members for driving
	RobotDrive* robotDrive;	//Robot Drive
	AnalogChannel* ir;		//Infrared Sensor, NOT USED
public:
	Drivetrain();
	~Drivetrain();
	void InitDefaultCommand();
	void SetInputValues(double x, double y);
	void SetDriveMode(DriveMode mode);
	double doubleAbsolute(double val);
	//Sends the smart 
	void SendSmartDashboardStatus();
private:
	void UpdateDrivetrain();
	void SetToIdleCommand();
};

#endif
