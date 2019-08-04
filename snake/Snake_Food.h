#pragma once

class Snake_Food
{
public:
	Snake_Food() {};
	void setDirection(Direction a);
	void addNode(int x,int y);
	void popNode(int x,int y);

private:
	Direction D;
	list<Node> li;
};

