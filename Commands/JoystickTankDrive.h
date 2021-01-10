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
#ifndef JOYSTICK_TANK_DRIVE_H
#define JOYSTICK_TANK_DRIVE_H

#include "../CommandBase.h"

/**
 *	Command: 		Joystick Tank Drive
 *	
 *	Description:	This command sets the Drivetrain to
 *					tank drive mode then starts sending
 *					joystick y values from the left and
 *					right joystick to the Drivetrain
 *
 * @author Mitchell Pell
 */
class JoystickTankDrive: public CommandBase {
public:
	JoystickTankDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
