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
#include "Drivetrain.h"
#include "../Commands/IdleBot.h"
#include "../Robotmap.h"

/*
 * Default Constructor
 */
Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	driveMode = IDLE;
	robotDrive = new RobotDrive(DRIVE_MOTOR_LEFT, DRIVE_MOTOR_RIGHT );
	//Set Timer
	timer = new Timer();
	timer->Reset();
	timer->Start();
	ir = new AnalogChannel(1);
	//Set Input Values
	inputValues = new double[4];
	for(int i = 0; i < 4; i++){inputValues[i] = (double)0;}
	
}
/*
 * Deconstructor. We created memory for the value
 * mapping dynamicly so we need to delete it.
 */
Drivetrain::~Drivetrain(){ delete[] inputValues; }

/*
 * This function sets the default command for this
 * Subsystem. We dont want the robot to take off on us
 * so we use IdleBot
 */
void Drivetrain::InitDefaultCommand() {
	// Set the default comman	d for a subsystem here.
	SetDefaultCommand(new IdleBot());
}
/*
 * PRIVATE HELPER: This function is used by this
 * Subsytem to set itself to the IdleBot command.
 * 
 * Used for when unsafe value changes are detected
 * and when input isnt changed soon enough 
 */
void Drivetrain::SetToIdleCommand()
{
	inputValues[0] = inputValues[2] = (double)0;
	inputValues[1] = inputValues[3] = (double)0;
	(new IdleBot())->Start();
}
/*
 * This accessor allows the Commands to change
 * the drive values.
 * 
 * Still works in IDLE mode, but nothing will happen
 */
void Drivetrain::SetInputValues(double x, double y)
{
	int dtCompleteStatus = 0;
	//If we are not IDLE, update input
	if ( driveMode == IDLE)
	{
		dtCompleteStatus = 1;
	}else
	{
		//First check for delay in input over 5 seconds
		if ( timer->Get() > MAX_INPUT_DELAY )
		{
			dtCompleteStatus = 2;
			SetToIdleCommand();
		}
		//Else, we have input within 5 seconds so continue to check
		else
		{
			
			//If the values are not changed, check if we need to
			//change to idle mode
			if (x == inputValues[0] && y == inputValues[1])
			{
				dtCompleteStatus = 3;
				//If input has not changed for 5 seconds
				if ( timer->Get() >= MAX_INPUT_DELAY )
				{
					SetToIdleCommand();
				}
			}
			//Else, grab the values being sent in
			else
			{
				
				//Check for major value jumps, and prevent change
				//If value change is too large
				if (doubleAbsolute( ((double)inputValues[2] - (double)x) ) >= MAX_VAL_CHANGE || 
					doubleAbsolute( ((double)inputValues[3] - (double)y) ) >= MAX_VAL_CHANGE)
				{
					SetToIdleCommand();
				//Else, update the values
				}else{
					//Store last input
					inputValues[2] = inputValues[0];
					inputValues[3] = inputValues[1];
					//Set new input
					inputValues[0] = x;
					inputValues[1] = y;
					//We got the values needed, reset the timer
					timer->Stop();
					timer->Reset();
					timer->Start();
				}
			}
		}
	}
	switch (dtCompleteStatus)
	{
		case 1:
			SmartDashboard::GetInstance()->
			PutString("Drivetrain setVal Complete Status: ",
					"Value not set, Robot is idle");
			break;
		case 2:
			SmartDashboard::GetInstance()->
			PutString("Drivetrain setVal Complete Status: ",
					"Value not set, Robot idle over 5 seconds");
			break;
		case 3:
			SmartDashboard::GetInstance()->
			PutString("Drivetrain setVal Complete Status: ",
					"Value not set, value didn't change");
			break;
		case 4:
			SmartDashboard::GetInstance()->
			PutString("Drivetrain setVal Complete Status: ",
					"Value not set, value change over max allowed");
			break;
		default:
			break;
	}
	UpdateDrivetrain();
}
/*
 * This accessor allows commands to change the Drivetrains
 * drive mode.
 */
void Drivetrain::SetDriveMode(DriveMode mode)
{
	driveMode = mode;
	//If we are leaving idle mode start the safe timer
	if ( driveMode != IDLE)
	{
		timer->Reset();
		timer->Start();
	}
	else
	{
		timer->Stop();
		timer->Reset();
	}
	UpdateDrivetrain();
}
/*
 * This function updates the Drivetrain after any changes
 * are made
 */
void Drivetrain::UpdateDrivetrain()
{
	switch (driveMode)
	{
	case IDLE:
		robotDrive->StopMotor();
		break;
	case TANK_DRIVE:
		robotDrive->TankDrive(inputValues[0],inputValues[1]);
		break;
	case ARCADE_DRIVE:
		robotDrive->ArcadeDrive(inputValues[0],inputValues[1]);
		break;
	}
}
/*
 * This function sends the Subsystems status values
 * over to the Smart Dashboard, Called by CommandBasedRobot.cpp
 */
void Drivetrain::SendSmartDashboardStatus()
{
	SmartDashboard* sd = SmartDashboard::GetInstance();
	sd->PutDouble("Drivetrain New X: ",inputValues[0]);
	sd->PutDouble("Drivetrain New Y: ",inputValues[1]);
	sd->PutDouble("Drivetrain Old X: ",inputValues[2]);
	sd->PutDouble("Drivetrain Old Y: ",inputValues[3]);
	switch (driveMode)
	{
	case IDLE:
		sd->PutString("Drivetrain Mode: ","Idle");
		break;
	case TANK_DRIVE:
		sd->PutString("Drivetrain Mode: ","Tank Drive");
		break;
	case ARCADE_DRIVE:
		sd->PutString("Drivetrain Mode: ","Arcade Drive");
		break;
	}
	sd->PutDouble("IR DATA: ", ir->GetVoltage());
}
/*
 * A little helper function to get the absolute
 * value of a number
 */
double Drivetrain::doubleAbsolute(double val){
	double returnable;
	if ( val < ((double)0) )
	{
		returnable = ( val * ((double)(-1)) );
	}
	else{
		returnable = val;
	}
	return returnable;
}
