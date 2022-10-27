#include <iostream>
using namespace std;
/*
short		2byte		-2e15 ~ 2e15 - 1
int			4byte		-2e31 ~ 2e31 - 1
long		4-8byte		-2e31 ~ 2e31 - 1
longlong	8byte		-2e63 ~ 2e63 - 1
*/

/*
sizeof ( 数据类型（int,long） 变量 )
*/

int main() {
	short sht = 10; // -32768 ~ 32767
	int	  itg = 10; // -4294967296 ~ 4294967295
	long  lng = 10; // -4294967296 ~ 4294967295
	long long llg = 10; // -** ~ **
	cout << "sizeof(short)= " 		<< sizeof(short)		<< "; sizeof(sht)="<<sizeof(sht) << endl;
	cout << "sizeof(int)= "			<<  sizeof(int)			<< "; sizeof(itg)= "<<sizeof(itg) << endl;
	cout << "sizeof(long)= "		<<  sizeof(long) 		<< "; sizeof(lng)= "<<sizeof(lng) << endl;
	cout << "sizeof(long long)= "	<<  sizeof(long long)	<< "; sizeof(llg)= "<<sizeof(llg) << endl;
	return 0;
}
