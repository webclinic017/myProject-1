#include <iostream>
using namespace std;
/*
打印星图
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 
*/

int main() {
	for (unsigned short i = 0; i < 5; i++) {
		for (unsigned short j = 0; j < 5; j++) {
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}
