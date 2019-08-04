#include "Snake_Food.h"
#include <list>

using namespace std;
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Node {
public:
	int x;
	int y;
	Node(int x,int y) {
		this->x = x;
		this->y = y;
	}
};

void Snake_Food::setDirection(Direction a) {
	D = a;
}

void Snake_Food::addNode(int x, int y) {
	//通知game增加蛇
	//生成食物
	Node node(x, y);
	li.push_front(node);
}

void popNode(int x, int y) {
	Node node = li.back();
	//通知game删除蛇
}