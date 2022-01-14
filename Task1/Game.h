#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>


#include "GameComponent.h"

using namespace std;

typedef void (*FP)();

class Game {
	// public member functions
public:
	Game(int mComponents) {
		this->maxComponents = mComponents;
	};
	void Add(GameComponent* gameComponent);
	void Run();
	void SetInitialise(void(*init)());
	void SetTerminate(void(*term)());

// private data members
private:
	int componentCount = 0;
	GameComponent* components[2]{};
	FP initialise{};
	FP terminate{};
	const int NUM_LOOPS = 5;
	const int TICKS_1000MS = 1000;
	int maxComponents;
	
};

//Add the new entity instances to the components object
void Game::Add(GameComponent* gameComponent) {
	if (componentCount == maxComponents) {
		cout << "Cannot add more than " << maxComponents << " game component(s)" << endl;
		return;
	} else {
		components[componentCount] = gameComponent;
		componentCount++;
	}
};

void Game::Run() {
	initialise();

	//Loop through the max number of times the entity will be called
	for (int x = 0; x < NUM_LOOPS; x++) {
		//Loop through each entity
		for (int i = 0; i < componentCount; i++) {

			// Current local time
			time_t t = time(0);
			tm* time = localtime(&t);
			components[i]->Update(time);
		}


		this_thread::sleep_for(chrono::milliseconds(TICKS_1000MS));
	}

	terminate();
};

void Game::SetInitialise(void (*init)()) {
	initialise = *init;
};

void Game::SetTerminate(void (*term)()) {
	terminate = *term;
};
