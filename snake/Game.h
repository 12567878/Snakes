#pragma once
class Game
{
public:
	Game(int a) {};
	static void print(Game g) {};
	Snake_Food s;
	void setLevel(int a) {}

private:
	long grade;
	Level L;
	vector<vector<char> > vec;
};

