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
#ifndef IDLE_BOT_H
#define IDLE_BOT_H

#include "../CommandBase.h"

/**
 *	Command: 		Joystic Arcade Drive
 *	
 *	Description:	This command sets the Drivetrain to
 *					idle mode.
 *
 * @author Mitchell Pell
 */
class IdleBot: public CommandBase {
public:
	IdleBot();
	virtual void Initialize();
	virtual void Execute(){}
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
