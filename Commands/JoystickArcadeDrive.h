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
#ifndef JOYSICK_ARCADE_DRIVE_H
#define JOYSICK_ARCADE_DRIVE_H

#include "../CommandBase.h"

/**
 *	Command: 		Joystic Arcade Drive
 *	
 *	Description:	This command sets the Drivetrain to
 *					arcade drive mode then starts sending
 *					joystick y and x values from the left
 *					joystick.
 *
 * @author Mitchell Pell
 */
class JoystickArcadeDrive: public CommandBase {
public:
	JoystickArcadeDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
