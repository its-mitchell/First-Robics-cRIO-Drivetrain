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
#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/IdleBot.h"
#include "Commands/KinectSafeStart.h"
#include "CommandBase.h"

/**======================================================
 * Class: 		Command Based Robot 
 * 
 * Description:	This is the starting point for the robots
 * 				programming.
 =======================================================*/
class CommandBasedRobot : public IterativeRobot {
private:
	/*---------------------------------------------
	 * Properties
	 ---------------------------------------------*/
	Command *autonomousCommand; //This is the command that starts in
								// autonomous mode
	//The two classes below are used to clean up the code below.
	// They will point to a single object each.
	// 	You could use  Kinect::GetInstance() each time you wanted
	// 	to use the kinect but thats messy so I assigned it to kinect
	//	in the constuctor.
	SmartDashboard* smartDashboard;
	Kinect* kinect;
	/*---------------------------------------------
	 * Function: Command Based Robot Constructor
	 ---------------------------------------------*/
	virtual void RobotInit() {
		//This creates and binds all the subsystems to
		// the commandbase, the commandbase is what
		// all commands inherit, giving them access
		CommandBase::init();
		smartDashboard = SmartDashboard::GetInstance();
		kinect = Kinect::GetInstance();
		//This will assign the autonomous command to
		// the idle bot command created
		autonomousCommand = new IdleBot();
	}
	/*---------------------------------------------
	 * Function: Starts autonomousCommand
	 ---------------------------------------------*/
	/**
	 * This function is called each time you enable
	 * autonomous mode
	 */
	virtual void AutonomousInit() {
		autonomousCommand->Start();
	}
	/*---------------------------------------------
	 * Function: Periodicly calls the autonomous
	 * commands update function
	 ---------------------------------------------*/
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	/*---------------------------------------------
	 * Function: Cancel autonomous command and start
	 * the teleop command.
	 ---------------------------------------------*/
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();
	}
	/*---------------------------------------------
	 * Function: Periodicly calls the teleop
	 * commands update function
	 ---------------------------------------------*/
	virtual void TeleopPeriodic() {

		tryKinectStart();	//This checks for Safe Kinect input constantly
							// and puts it into kinect drive mode when the start
							// values are read.   It's also kind of lazy code :)
		
		updateSDStatus();	//This prints values to the Smart Dashboard (optional)
		Scheduler::GetInstance()->Run(); //This calles all the active commands
	}
	/*
	 * This function checks for safe kinect starting values
	 * using the static method included in the KinectSafeStart command
	 */
	void tryKinectStart()
	{
		if (KinectSafeStart::isSafeToStart())
		{
			(new KinectTankDrive())->Start();
		}
	}
	/*
	 * This function updates the values being sent to the Smart Dashboard
	 * 		Note: The Smart Dashboard is optional, and it does kill the 
	 * 		Dashboard that comes with the Driver Station when installed.
	 */
	void updateSDStatus(){

		//Print Kinect Status
		//kinect->
		smartDashboard->PutInt("Kinect Player Count: ",
				kinect->GetNumberOfPlayers());
		smartDashboard->PutBoolean("Kinect Player Tracked: ",(
				kinect->GetTrackingState(1) == Kinect::kTracked));
		smartDashboard->PutInt("Kinect Player Quality: ",
				kinect->GetQuality(1));

			smartDashboard->PutDouble("Kinect Left Arm Y: ",
					CommandBase::oi->getKinectLeftArmY());
			smartDashboard->PutDouble("Kinect Left Arm X: ",
					CommandBase::oi->getKinectLeftArmX());
			smartDashboard->PutDouble("Kinect Right Arm Y: ",
					CommandBase::oi->getKinectRightArmY());
			smartDashboard->PutDouble("Kinect Right Arm X: ",
					CommandBase::oi->getKinectRightArmX());

		//Print Joystick Input
		smartDashboard->PutDouble("Left Joy Y",
				CommandBase::oi->getLeftJoyY());
		smartDashboard->PutDouble("Right Joy Y",
				CommandBase::oi->getRightJoyY());
		smartDashboard->PutDouble("Left Joy X",
				CommandBase::oi->getLeftJoyX());
		smartDashboard->PutDouble("Right Joy X",
				CommandBase::oi->getRightJoyX());
		//Have the drive train send its status
		CommandBase::drivetrain->SendSmartDashboardStatus();
	}
	
};
/**======================================================
 * The start of it all! The Big Bang!
 =======================================================*/
START_ROBOT_CLASS(CommandBasedRobot);

