/*#####################################################
# Name:			CommandBase Header File
# Description:	This is the Header file that defines
#				the CommandBase. The CommandBase is
#				what every command inherits for 
#				common control. The CommandBase
#				main use is to link the Subsystems
#				and OI class to allow each command
#				access to them.
#
# Author:		Mitchell Pell
# Version:		1.0
# Date:			06/14/2012 (mm/dd/yyy)
#
# History:		1.0 - MP - First make.
#
######################################################*/
#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
//Include the subsystems for the commands to access
#include "Subsystems/CameraControl.h"
#include "Subsystems/Drivetrain.h"
#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static CameraControl*	cameraControl;
	static Drivetrain*		drivetrain;
	static OI*				oi;
};

#endif
