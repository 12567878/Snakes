#include "Game.h"
#include "Snake_Food.h"
#include <iostream>
#include <vector>
using namespace std;

enum Level {
	EASY,
	NORMAL,
	HARD
};

Game::Game(int a) :s(),vec(25,vector<char>(40)){
	setLevel(a);
}

void Game::setLevel(int a) {    //namespace记得带上
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
