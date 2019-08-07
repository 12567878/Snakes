#pragma once




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
	Node(int,int);
	
};

class Snake
{
public:
	Snake() ;
	void setDirection(int a);
	void addNode(int x,int y);
	Node pop_back();
	Direction getDirection();
	void setOppoD();
	Node getSecond();
private:
	Direction D;
	vector<Node> li;//¸Ä³Évector
};

