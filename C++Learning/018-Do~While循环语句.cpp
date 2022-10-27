#include <iostream>
using namespace std;
/*
do{
	执行语句
}
while(条件);

它会先执行一次do{执行语句},然后再while判断，如果为真会再do{执行语句}，直到while判断为假。
*/

int main() {
	unsigned short num = 0;
	
	do {
		cout << num++ << endl;
	} 
	while (num < 10);
	
	return 0;
}
