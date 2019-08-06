#pragma once


class Game
{
public:
	Game(int a) {};
	static void print(Game& g) {};
	Snake s;
	void setLevel(int a) {}
	static void setBound(Game& g);
	void addNode(int x, int y);
	void pop_back();
	void createFood();
private:
	long grade;
	Level L;
	vector<vector<char> > vec;
};

