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
#include "KinectSafeStart.h"

KinectSafeStart::KinectSafeStart() {
	// Use requires() here to declare subsystem dependencies
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void KinectSafeStart::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void KinectSafeStart::Execute() {
	if ( isSafeToStart() )
	{
		(new KinectTankDrive())->Start();
	}
}
/*
 * This static function is for any part of the program to check
 * for the kinect arms to be zeroed (as in between a range and not 0)
 */
bool KinectSafeStart::isSafeToStart()
{
	static int safeStarts = 0;

	bool results = false;
	Kinect* k = Kinect::GetInstance();
	//First make sure the skeleton is in the right position
	if ( isReadingSafeSkeleton(k) )
	{
		float l =  oi->getKinectLeftArmY();
		float r = oi->getKinectRightArmY();
		
		if (l < SAFE_START_BOUNDS && l > (-SAFE_START_BOUNDS) && r < SAFE_START_BOUNDS && r > (-SAFE_START_BOUNDS) &&
			l != 0.0 && r != 0.0)
		{
			safeStarts++;
			results = true;
		}
	}
	SmartDashboard::GetInstance()->PutInt("Kinect Safe Start >>> ",safeStarts);
	return results;
}
/*
 * This function is for any part of the program to make sure the Kinect
 * is sending valid data to the robot.
 */
bool KinectSafeStart::isReadingSafeSkeleton(Kinect* k)
{
	
	bool results = false;
	int position = 0;

	if ( k->GetNumberOfPlayers() > 0 )
	{
			//Check Skeletons position quality
			position = k->GetQuality(0);
			if (k->GetQuality(0) != Kinect::kClippedLeft &&
				k->GetQuality(0) != Kinect::kClippedRight &&
				k->GetQuality(0) != Kinect::kClippedTop &&
				k->GetQuality(0) != (Kinect::kClippedTop + Kinect::kClippedLeft) &&
				k->GetQuality(0) != (Kinect::kClippedTop + Kinect::kClippedRight))
			{
				results = true;
			}
		}
	SmartDashboard::GetInstance()->PutBoolean("Kinect Safe Read >>> ",results);
	return results;
}

// Make this return true when this Command no longer needs to run execute()
bool KinectSafeStart::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void KinectSafeStart::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KinectSafeStart::Interrupted() {
}
