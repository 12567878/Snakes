#include "Snake.h"
#include <list>

using namespace std;
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

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
	//֪ͨgame������
	//����ʳ��
	Node node=Node(x, y);
	li.push_front(node);
}

Node Snake::pop_back() {   //�ǵ�Snake::
	Node n = li.back();
	li.pop_back();
	return n;
	//֪ͨgameɾ����
}
Direction Snake::getDirection() {
	return this->D;
}