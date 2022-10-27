#include <iostream>
using namespace std;
/*

*/

int main() {
	string str = "XXX";
	str.insert(1,"000");
	cout << str << endl;
	str.erase(1,3);
	cout << str << endl;
	return 0;
}
