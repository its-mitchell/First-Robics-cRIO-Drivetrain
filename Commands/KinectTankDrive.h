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
#ifndef KINECT_TANK_DRIVE_H
#define KINECT_TANK_DRIVE_H

#include "../CommandBase.h"
#include "../Robotmap.h"
#include "../Commands/KinectSafeStart.h"
/**
 *	Command: 		Kinect Tank Drive
 *	
 *	Description:	This command takes values from the
 *					kinnect and passes them to the 
 *					Drivetrain subsystem.
 *
 * @author Mitchell Pell
 */
class KinectTankDrive: public CommandBase {
public:
	KinectTankDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
