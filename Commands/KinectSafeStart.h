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
#ifndef KINECT_SAFE_START_H
#define KINECT_SAFE_START_H

#include "../CommandBase.h"
#include "../Commands/KinectTankDrive.h"
#include "../Robotmap.h"
/**
 *	Command: 		Kinect Safe Start
 *	
 *	Description:	This command constantly checks
 *					for safe input then starts the 
 *					Kinect Tank Drive command
 *
 * @author Mitchell Pell
 */
class KinectSafeStart: public CommandBase {
public:
	//Must have arms in safe bounds to start robot
	//  Defined in RobotMap.h
	//static const float SAFE_START_BOUNDS = 0.0125f;
	
	KinectSafeStart();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	//Below are function used globaly to check the kinects
	// values
	static bool isReadingSafeSkeleton(Kinect* kinect);
	static bool	isSafeToStart();
};
#endif
