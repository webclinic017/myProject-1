#include <iostream>
using namespace std;
/*
敲桌子：0-100；如果个位或十位有7或是7的倍数，打印敲桌子。
*/

int main() {
	for (unsigned short i = 1; i <= 100; i++) {
		if ((i % 10 == 7) || (i / 10 % 10 == 7) || (i % 7 == 0)) {
			cout << "敲桌子" << endl;
		}
		else {
			cout << i << endl;
		}
	}
	return 0;
}
