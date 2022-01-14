
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"

using namespace std;

void Init() {
	cout << "Initialising game" << endl;
};

void Terminate() {
	cout << "Terminating game" << endl;
};

int main() {
	//Dynamic instance of Game
	auto* game = new Game(2);

	//Assign the stand alone functions to the Game instance
	game->SetInitialise(*Init);
	game->SetTerminate(*Terminate);

	//Entities calling parent and then child to be added to the array
	game->Add(new GameComponent());
	game->Add(new DrawableGameComponent(0, 0));

	// iterates throguh the components with the 1 second interval defined 
	game->Run();

	return 0;

}