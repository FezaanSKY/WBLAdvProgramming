#pragma once
#include <iostream>
#include <string>
#include "GameComponent.h"
#include <ctime>

using namespace std;

enum Direction {
	Right,
	Left,
	Up,
	Down
};

class DrawableGameComponent : public GameComponent 
{
public:
	DrawableGameComponent(int x, int y) {
		direction = Right;
		directionString = "Right";
		this->x = x;
		this->y = y;
	};

	Direction direction;
	const int SCREEN_HEIGHT = 20;
	const int SCREEN_WIDTH = 80;

	void Update(const tm* eventTime) override;

private:
	void UpdatePositions();
	void ChangeDirection();
	void Draw();
	int GetRandomNum();
	int x;
	int y;
	string directionString;
};

void DrawableGameComponent::Update(const tm* eventTime) {
	GameComponent::Update(eventTime);
	UpdatePositions();
	Draw();
	ChangeDirection();
};

// Random number generated between 0 to 3
int DrawableGameComponent::GetRandomNum() {
	srand(time(NULL));
	return rand() % 4;
}

//Update x & y values based off direction
void DrawableGameComponent::UpdatePositions() {
	switch (direction) {
	case Left:
		x--;
		if (x < 0) {
			x = 0;
		}
		directionString = "Left";
		break;
	case Right:
		x++;
		if (x > SCREEN_WIDTH) {
			x = SCREEN_WIDTH;
		}
		directionString = "Right";
		break;
	case Up:
		y++;
		if (y > SCREEN_HEIGHT) {
			y = SCREEN_HEIGHT;
		}
		directionString = "Up";
		break;
	case Down:
		y--;
		if (y < 0) {
			y = 0;
		}
		directionString = "Down";
		break;
	default:
		x = 0;
		y = 0;
		break;
	}
}



//Ensure state value (right,left,up & down) different to the previous generated state
void DrawableGameComponent::ChangeDirection() {
	int randomNumber = GetRandomNum();
	while (randomNumber == direction) {
		randomNumber = GetRandomNum();
	}
	direction = static_cast<Direction>(randomNumber);
};


void DrawableGameComponent::Draw() {
	cout << directionString << " : " << "X: " << x << " Y: " << y << endl;
};
