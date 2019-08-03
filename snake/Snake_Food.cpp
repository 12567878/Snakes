#include "Snake_Food.h"
#include<vector>
using namespace std;
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

Snake_Food::Snake_Food() : vec(20,vector<int>(20)){
	D = RIGHT;
}

void Snake_Food::setDirection(int a) {
	switch (a)
	{
	
	default:
		break;
	}
}