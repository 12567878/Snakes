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
	if (Food::s) {
		srand((unsigned)time(NULL));
		Food::s = false;
	}
	Food::x = 1 + rand() % 23; //����1-23֮������
	Food::y = 1 + rand() % 23;

}