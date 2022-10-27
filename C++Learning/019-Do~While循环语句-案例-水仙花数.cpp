#include <iostream>
using namespace std;
/*
三位数，个^3+十^3+百^3 = 本身
*/

// c++ 幂运算 pow(a,次)

int main() {
	unsigned short num = 100;
	unsigned short a,b,c;
	do {
		a = num / 100;
		b = (num - a * 100) / 10;
		c = (num - a * 100 - b * 10);
		if ((a*a*a + b*b*b + c*c*c) == num) {
			cout << num << endl;
		}
		++num;
	} while(num < 1000);


	return 0;
}
