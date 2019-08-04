#include <iostream>
#include <string>
#include "Snake_Food.h"
#include "Game.h"
#include <conio.h>
#include "Snake_Food.cpp"
using namespace std;


int main()
{
    cout << "Welcome! Press Any Key to Start."<<endl;
	getchar();
	cout << "Please Choose the Level.\n" << "Input 1，2，3 and Enter to Choose Easy,Normal and Hard."<< endl;
	cout << "Your choice: ";
	int a = 0,b = 0;  cin >> a>> b;
	Game game(a);						//构造game ，初始化参数
	do {
		
		Game::print(game);  //记得退格
		
		while (/*计时器*/) {
			int ch;
			switch (ch)
			{
			case 0xE0:
				switch (ch = _getch())
				{
				case 72:  game.s.setDirection(Direction::UP); break;
				case 80:  game.s.setDirection(Direction::DOWN); break;
				case 75:  game.s.setDirection(Direction::LEFT); break;
				case 77:  game.s.setDirection(Direction::RIGHT); break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			_sleep(0.1);
		}
						  

		//根据输入决定方向，更新画面

	
	} while (/*没吃自己没撞墙*/);             //可以以此为最后画面，不需演示穿模
	//结束以后光标回到末尾，打印you fail;
	//更新成绩文件，ofstream
	//询问是否重来（需要再加一个循环）
	
	return 0;
}
