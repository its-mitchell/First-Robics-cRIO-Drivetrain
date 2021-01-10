/*#####################################################
# Name:			CommandBase Code File
# Description:	
#
# Author:		Mitchell Pell
# Version:		1.0
# Date:			06/14/2012 (mm/dd/yyy)
#
# History:		1.0 - MP - First make.
#
######################################################*/
#include "CommandBase.h"
//Include the subsystems for the commands to access
#include "Subsystems/CameraControl.h"
#include "Subsystems/Drivetrain.h"
#include "Commands/Scheduler.h"

/*
 * This will simply pass the new commands name to the command base
 * to pass to command so the newly created command can be identified
 */
CommandBase::CommandBase(const char *name) : Command(name) {
	
}
/*
 * This is the same as above, but with no command name given
 */
CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
//  This prevents multiple versions of each subsystem, we don't want that
OI* CommandBase::oi = NULL;
CameraControl* CommandBase::cameraControl = NULL;
Drivetrain* CommandBase::drivetrain = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	cameraControl = new CameraControl();
	drivetrain = new Drivetrain();
	oi = new OI();
}
