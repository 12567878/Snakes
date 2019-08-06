#pragma once

enum Direction;

class Node {
public:
	int x;
	int y;
	Node(int,int);
	
};

class Snake
{
public:
	Snake() {};
	void setDirection(int a);
	void addNode(int x,int y);
	Node pop_back();
	Direction getDirection();

private:
	Direction D;
	list<Node> li;//¸Ä³Évector
};

