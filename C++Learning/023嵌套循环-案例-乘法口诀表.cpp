#include <iostream>
using namespace std;
/*

*/

int main() {
	for (unsigned short i = 1; i <= 9; i++) {
		for (unsigned short j = 1; j <= i; j++) {
			cout << j << " x " << i << " = " << j*i << "\t";
		}
		cout << endl;
	}	
	return 0;
}
