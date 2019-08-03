#include "Game.h"
#include "Snake_Food.h"
#include <iostream>
using namespace std;

enum Level {
	EASY,
	NORMAL,
	HARD
};
Game::Game(int a) {
	switch (a)
	{
	case 1:
		L = EASY;
		break;
	case 2:
		L = NORMAL;
		break;
	case 3:
		L = HARD;
		break;
	default:
		std::cout << "Your input is not right." << endl;
		break;
	}
}
