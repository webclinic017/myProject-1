#include <iostream>
using namespace std;
/*

*/

int main() {
	string s = "12345678901234567890";
	int pos = s.find("5",10);
	cout << pos << endl;
	s.replace(2,2,"哈哈哈哈");
	cout << s << endl;
	
	return 0;
}
