#include <iostream>
#include <string>
#include <vector>
#include <random>
#include<time.h>
#include <conio.h>
#include <Windows.h>
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
	Node(int, int);

};

class Snake
{
public:
	Snake() ;
	void setDirection(int a);
	void addNode(int x, int y);
	Node pop_back();
	Direction getDirection();
	void setOppoD();
	Node getSecond();
	int getGrade();
private:
	Direction D;
	vector<Node> li;//改成vector
};

class Food
{
public:
	int x;
	int y;
	bool s;
	Food();
	void createFood();

};



enum Level {
	EASY,
	NORMAL,
	HARD
};

class Game
{
public:
	Game(int a) ;
	static void print(Game& g) ;
	Snake s;
	void setLevel(int a);
	static void setBound(Game& g);
	void addNode(int x, int y);
	void pop_back();
	void createFood();
	char hasWhat(int, int);
	vector<vector<char> > vec;
	Level getLevel();
private:
	long grade;
	Level L;

};






Food::Food() {
	x = 0;
	y = 0;
	s = true;
}

void Food::createFood() {
	if (s) {
		srand((unsigned)time(NULL));
		s = false;
	}
	x = 1 + rand() % 23; //产生1-23之间整数
	y = 1 + rand() % 23;

}



Node::Node(int x, int y) {
	this->x = x;
	this->y = y;
}

Snake::Snake() :li(){     //忘记写了
	D = Direction::RIGHT;
	
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
	Node node = Node(x, y);
	if (li.size() == 0) { li.push_back(node); }
	else li.insert(li.begin(), node);
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
	if (li.size() > 1) { return this->li[1]; }
	else { Node node = Node(-1, -1); return node; }
}

int Snake::getGrade() {
	return this->li.size() - 1;
}

using namespace std;

Level Game::getLevel() {
	return L;
}

Game::Game(int a) :s(), vec(25, vector<char>(25, ' ')) {         //pass
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
		std::cout << "Your input is not right.The default level is easy." << endl;
		L = EASY;
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
	} while (this->vec[a.x][a.y] == 's');
	this->vec[a.x][a.y] = 'f';
}

char Game::hasWhat(int x, int y) {
	return this->vec[x][y];
}

int getJ(Level L) {
	int t = 0;
	switch (L)
	{
	case EASY:
		t = 20;
		break;
	case NORMAL:
		t = 10;
		break;
	case HARD:
		t = 5;
		break;
	default:
		break;
	}
	return t;
}

int main()
{
	cout << "Welcome! Press Any Key to Start." << endl;
	getchar();
	cout << "Please Choose the Level.\n" << "Input 1，2，3 and Enter to Choose Easy,Normal and Hard." << endl;
	cout << "Your choice: ";
	int a = 0;  cin >> a ;  //b干啥的+		game	{s={D=RIGHT (3) li={ size=0 } } vec={ size=25 } grade=0 ...}	Game

	Game game = Game(a);	//构造game ，初始化参数   竟然今天都不会构造！！！ 可以花括号（Game g{a};）
	Game::setBound(game);
	int x1 = 13;
	int y1 = 13;//记录坐标
	int x2 = 0;
	int y2 = 0;

	game.addNode(x1, y1);
	game.createFood();
	bool flag=true;



	do {

		Game::print(game);
		cout << "Game mode : " << game.getLevel()+1 << endl;
		cout << "Your grade : " << game.s.getGrade() << endl;
		int vv = 0;
		vv = getJ(game.getLevel());
		int j = 0;
		while (j < vv) {         //计时器   //truly pass 
			int ch = 0;
			if (_kbhit()) {
				ch = _getch();  //pass
				switch (ch)
				{
				case 0xE0:
					ch = _getch();
					game.s.setDirection(ch);
					break;
				default:
					break;
				}
				Sleep(20);

			}
			else Sleep(20);
			++j;  //放错地方了
			//cout << "1";
		}
		switch (game.s.getDirection())
		{
		case Direction::UP: {x2 = x1 - 1; y2 = y1; break; }
		case Direction::DOWN: {x2 = x1 + 1; y2 = y1; break; }
		case Direction::LEFT: {x2 = x1; y2 = y1 - 1; break; }
		case Direction::RIGHT: {x2 = x1; y2 = y1 + 1; break; }
		default:
			break;
		}

		if (game.hasWhat(x2, y2) == ' ') {//根据输入决定方向，更新画面
			game.addNode(x2, y2);
			game.pop_back();
			x1 = x2; y1 = y2;//忘记更新坐标了
			system("cls");//退格system("cls");
		}
		else if (game.hasWhat(x2, y2) == 'f') {
			game.addNode(x2, y2);        //不用删除食物  
			game.createFood();
			x1 = x2; y1 = y2;
			system("cls");//退格
		}
		else if (x2 == game.s.getSecond().x && y2 == game.s.getSecond().y) {   //撞墙吃自己
			game.s.setOppoD();
			switch (game.s.getDirection())
			{
			case Direction::UP: {x2 = x1 - 1; y2 = y1; break; }
			case Direction::DOWN: {x2 = x1 + 1; y2 = y1; break; }
			case Direction::LEFT: {x2 = x1; y2 = y1 - 1; break; }
			case Direction::RIGHT: {x2 = x1; y2 = y1 + 1; break; }
			default:
				break;
			}
			game.addNode(x2, y2);
			game.pop_back();
			x1 = x2; y1 = y2;
			system("cls");//退格system("cls");
		}
		else {
			flag = false;
		}



	} while (flag);             //可以以此为最后画面，不需演示穿模
	cout << "You Fail!" << endl;
	cout << "Your grade is: " << game.s.getGrade() << endl;
	getchar();
	getchar();
	
	//更新成绩文件，ofstream
	//询问是否重来（需要再加一个循环）

	return 0;
}