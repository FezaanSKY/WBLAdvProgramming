#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class GameComponent {
public:
	GameComponent() {
		id = ++ instances;
	};
	virtual void Update(const tm* eventTime);

private:
	int id;
	static int instances;
};

//Value of instances set to 0 
int GameComponent::instances;

//ID and time format (HH:MM:SS)
void GameComponent::Update(const tm* eventTime) {
	cout << "ID: " << id << " Updated: " << put_time(eventTime, "%T") << endl;
};
