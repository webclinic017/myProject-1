#include <iostream>
using namespace std;
/*
只占用1个byte
true  会被c++识别为：1
false 会被c++识别为：0
*/

int main() {
	bool bol = true;
	bol = false;
	cout << "bol=" << bol << endl;
	cout << "size of bool: " <<sizeof(bol) << endl;
	return 0;
}
