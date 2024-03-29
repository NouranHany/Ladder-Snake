
#pragma once
#include "Card.h"

class CardSix : public Card
{
public:
	CardSix(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardSix which is: 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player

	virtual ~CardSix(); // A Virtual Destructor

};
