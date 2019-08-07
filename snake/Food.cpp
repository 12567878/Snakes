#include "Food.h"
#include <random>
#include<time.h>
using namespace std;

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