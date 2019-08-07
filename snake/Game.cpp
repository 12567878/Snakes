#include "Game.h"
#include "Snake.h"
#include <iostream>
#include <vector>
#include <list>
#include "Food.h"
using namespace std;



Game::Game(int a) :s(),vec(25,vector<char>(25,' ')){         //pass
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

void Game::print(Game& g) {               //pass
	vector<vector<char> >vec = g.vec;
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < vec[i].size(); ++j) {
			cout << vec[i][j];
		}
		cout << '\n';
	}
}

 void Game::setBound(Game& g) {              //不用加static，pass
	g.vec[0] = vector<char>(25, '*');
	g.vec[g.vec.size() - 1] = vector<char>(25, '*');
	for (int i = 0; i < g.vec.size(); ++i) {
		g.vec[i][0] = '*';
		g.vec[i][g.vec[i].size() - 1] = '*';
	}
}

 void Game::addNode(int x, int y) {
	 this->s.addNode(x, y);
	 this->vec[x][y] = 's';
 }

 void Game::pop_back() {
	Node n = this->s.pop_back();
	int x = n.x; int y = n.y;
	this->vec[x][y] = ' ';
 }

 void Game::createFood() {
	 Food a = Food();
	 do { 
		 a.createFood(); 
	 } while (this->vec[a.x][a.y] != 's');
	 this->vec[a.x][a.y] = 'f';
 }

 char Game::hasWhat(int x,int y) {
	 return this->vec[x][y];
 }