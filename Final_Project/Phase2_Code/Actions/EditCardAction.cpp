#include "EditCardAction.h"
#include "../GUIClasses/Input.h"
#include "../GUIClasses/Output.h"
#include "../GameObjects/Cards/CardOne.h"
#include "../GameObjects/Cards/CardTwo.h"
#include "../GameObjects/Cards/CardThree.h"
#include "../GameObjects/Cards/CardFour.h"
#include "../GameObjects/Cards/CardFive.h"
#include "../GameObjects/Cards/CardSix.h"
#include "../GameObjects/Cards/CardSeven.h"
#include "../GameObjects/Cards/CardEight.h"
#include "../GameObjects/Cards/CardNine.h"
#include "../GameObjects/Cards/CardTen.h"
#include "../GameObjects/Cards/CardEleven.h"
#include "../GameObjects/Cards/CardTwelve.h"
#include "../GameObjects/Cards/CardThirteen.h"
#include "../GameObjects/Cards/CardFourteen.h"


EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


EditCardAction::~EditCardAction()
{
}


void EditCardAction::ReadActionParameters()
{
	//Getting a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();


	//Reading the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Click on the cell you would like to Edit... ");
	cardPosition = pIn->GetCellClicked(); //N//Both vCell and hCell of the cell will be set to -1 if the click isn't within the grid range

	
	//Making the needed validations on the read parameters
	if (cardPosition.HCell() == -1 || cardPosition.VCell() == -1)
	{

		cardNumber = -1;
		editedCard = NULL;
		pGrid->PrintErrorMessage("Invalid position, Operation cancelled, click to continue... ");
		return;
	}

	editedCard = pGrid->HasCard(cardPosition);
	
	if (editedCard == NULL)
	{
		pGrid->PrintErrorMessage("Invalid Editing, This Cell doesn't contain a Card, click to continue... ");
		editedCard == NULL;
		return;
	} 
	else
	{
		if (dynamic_cast<CardThree*>(editedCard) || dynamic_cast<CardFour*>(editedCard) || dynamic_cast<CardFive*>(editedCard) || dynamic_cast<CardSix*>(editedCard) || dynamic_cast<CardSeven*>(editedCard) || dynamic_cast<CardEight*>(editedCard))
		{
			pGrid->PrintErrorMessage("Invalid Editing, This Card doesn't take values to be edited, click to continue... ");
			editedCard == NULL;
			return;
		}

	}

	cardNumber = editedCard->GetCardNumber();

	// 5- Clear status bar
	pOut->ClearStatusBar();
}



void EditCardAction::Execute()
{
	//The first line of any Action Execution is to read its parameter first
	ReadActionParameters();


	if (editedCard)
	{
		//Done// A- We get a pointer to the Grid from the ApplicationManager
		Grid * pGrid = pManager->GetGrid();
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();

		// B- Edit the card parameters: EditCardParameters(), It is virtual and depends on the card type
		// D- if, the appropriate error message on statusbar will be printed

		editedCard->EditCardParameters(pGrid);

		pOut->ClearStatusBar();

	}
}







