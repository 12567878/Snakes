#include <iostream>
#include "snake.h"
#include "Game.h"
using namespace std;


int main()
{
    cout << "Welcome! Press Any Key to Start."<<endl;
	getchar();
	//构造game ，初始化参数
	while (/*没吃自己没撞墙*/) {
		//while一段时间   持续获取输入
		
		//根据输入决定方向，更新画面

		print(/*当前画面*/);  //记得退格
	
	}
	//结束以后光标回到末尾，打印you fail;
	//更新成绩文件，ofstream
	//询问是否重来（需要再加一个循环）
	
	return 0;
}

void print() {

}