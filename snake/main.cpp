#include <iostream>
#include <string>
#include <vector>
#include "Food.h"
#include "Snake.h"
#include "Game.h"
#include <conio.h>
#include <Windows.h>

using namespace std;


int main()
{
    cout << "Welcome! Press Any Key to Start."<<endl;
	getchar();
	cout << "Please Choose the Level.\n" << "Input 1，2，3 and Enter to Choose Easy,Normal and Hard."<< endl;
	cout << "Your choice: ";
	int a = 0,b = 0;  cin >> a>> b;  //b干啥的
	Game game=Game(a);	//构造game ，初始化参数   竟然今天都不会构造！！！ 可以花括号（Game g{a};）
	Game::setBound(game);
	int x1 = 13;
	int y1 = 13;//记录坐标
	int x2 = 0;
	int y2 = 0;

	game.addNode(x1, y1);
	game.createFood();
	bool flag;


	do {
		
		Game::print(game);  
		
		int j = 0;
		while (j<=10) {         //计时器
			int ch;
			ch = _getch();
			switch (ch)
			{
			case 0xE0:
				ch = _getch();
				game.s.setDirection(ch);
				break;
			default:
				break;
			}
			Sleep(1);
			++j;
			}
		switch (game.s.getDirection())
		{
		case Direction::UP: {x2 = x1 - 1; y2 = y1; break; }
		case Direction::DOWN: {x2 = x1 + 1; y2 = y1; break; }
		case Direction::LEFT: {x2 = x1; y2 = y1-1; break; }
		case Direction::RIGHT: {x2 = x1; y2 = y1+1; break; }
		default:
			break;
		}

		if (game.hasWhat(x2,y2)==' ') {//根据输入决定方向，更新画面
			game.addNode(x2, y2);
			game.pop_back();
			system("cls");//退格system("cls");
		}
		else if (game.hasWhat(x2, y2) == 'f') {
			game.addNode(x2, y2);        //不用删除食物  
			game.createFood();
			system("cls");//退格
		}
		else if(x2==game.s.getSecond().x&&y2== game.s.getSecond().y){   //撞墙吃自己
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
			system("cls");//退格system("cls");
		}
		else {
			flag = false;
		}

		
	
	} while (flag);             //可以以此为最后画面，不需演示穿模
	cout << "You Fail!" << endl;
	//更新成绩文件，ofstream
	//询问是否重来（需要再加一个循环）
	
	return 0;
}

