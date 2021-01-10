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
#ifndef CONTROL_CAMERA_H
#define CONTROL_CAMERA_H

#include "../CommandBase.h"

/**
 * This class is a Command that initiates control
 * over the camera subsystem untill interupted by
 * another command.
 * 
 * @author Mitchell Pell
 */
class ControlCamera: public CommandBase {
public:
	//Required functions (All exist in CommandBase)
	ControlCamera();
	//Virtual = Overrides the CommandBase Function
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
