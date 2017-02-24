// Atelier 1
// pong.cc

#include "GameView.h"
#include "GameModel.h"
#include "shoot_const.h"
#include "Element.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void game()
{
	srand(time(NULL));

	GameModel* model = new GameModel(MODEL_WIDTH, MODEL_HEIGHT);
	GameView* view = new GameView(VIEW_WIDTH, VIEW_HEIGHT, VIEW_BPP);
	view->setModel(model);

	//~ view->
	while(view->treatEvents() and model->getInGame()){
	  
		model->nextStep();
		if (!model->getInGame())
		{
			if (!model->getLevelPassed())
			{
				while (view->treatEventsTransition())
				{
					view->drawTransition(model->getLevelPassed());
					if (model->getPlayerLife() >= 0)
						model->setInGame(true);
				}
			}
			else
			//~ if (model->getLevelPassed())
			{
				while (view->treatEventsTransition())
				{
					view->drawTransition(model->getLevelPassed());
				}
				model->setLevelPassed(false);
				model->setInGame(true);
			}
			
		} 
		view->synchronize();
		view->draw();

	}

	delete view;
	delete model;
}

int menu()
{
	srand(time(NULL));
	GameView* view = new GameView(VIEW_WIDTH, VIEW_HEIGHT, VIEW_BPP);
	while (view->treatEventsOpening())
		view->drawOpening();
	
	int ret = view->treatEventsMenu();
	while(ret == 1){
	  
		//~ model->nextStep();
		//~ view->synchronize();
		view->drawMenu();

		ret = view->treatEventsMenu();
	}
	return ret;
}

int main(){

	int a = menu();
	while ( a != 0 )
	{		
		if (a == 2)
			game();
		a = menu();
	}
	return EXIT_SUCCESS;
}
