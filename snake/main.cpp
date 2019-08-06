#include <iostream>
#include <string>
#include "Snake.h"
#include "Game.h"
#include <conio.h>
#include "Food.h"

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
	game.addNode(x1, y1);
	game.createFood();
	bool flag;


	do {
		
		Game::print(game);  
		
		int j = 0;
		while (j<=10) {         //计时器
			int ch;
			switch (ch)
			{
			case 0xE0:
				game.s.setDirection(ch);
				break;
			default:
				break;
			}
			_sleep(0.1);
			++j;
			
		}
		if (/*前方没有*/) {//根据输入决定方向，更新画面
			//addNode
			//popNode
			//退格
		}
		else if (/*有food*/) {
			//addNode 
			//createFood
			//退格
		}
		else {   //撞墙吃自己
			flag = false;
		}
		
	
	} while (flag);             //可以以此为最后画面，不需演示穿模
	//结束以后光标回到末尾，打印you fail;
	//更新成绩文件，ofstream
	//询问是否重来（需要再加一个循环）
	
	return 0;
}
