#include "Snake.h"
#include <vector>


using namespace std;

Node::Node(int x, int y) {
	this->x = x;
	this->y = y;
}


void Snake::setDirection(int a) {
	switch (a)
	{
	case 72: D = Direction::UP; break;
	case 80: D = Direction::DOWN; break;
	case 75: D = Direction::LEFT; break;
	case 77: D = Direction::RIGHT; break;
	default:
		break;
	}
}

void Snake::addNode(int x, int y) {
	//通知game增加蛇
	//生成食物
	Node node=Node(x, y);
	li.insert(0,node);
}

Node Snake::pop_back() {   //记得Snake::
	Node n = li.back();
	li.pop_back();
	return n;
	//通知game删除蛇
}
Direction Snake::getDirection() {
	return this->D;
}
void Snake::setOppoD() {
	switch (D)
	{
	case UP:
		D = DOWN;
		break;
	case DOWN:
		D = UP;
		break;
	case LEFT:
		D = RIGHT;
		break;
	case RIGHT:
		D = LEFT;
		break;
	default:
		break;
	}
}

Node Snake::getSecond() {
	return this->li[1];
}