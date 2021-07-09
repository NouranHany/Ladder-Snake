#pragma once

#include "Action.h"

class CopyCardAction : public Action
{
	// [Action Parameters]
	CellPosition cardPosition; // cell position of the card


public:
	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads action parameters ( cardPosition)

	virtual void Execute();

	virtual ~CopyCardAction(); // A Virtual Destructor
};

