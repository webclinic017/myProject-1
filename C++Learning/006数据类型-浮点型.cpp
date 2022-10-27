#include <iostream>
using namespace std;
/*
float	单精度	4byte	小数点前后共7位有效数字
double	双精度	8byte	小数点前后共15-16位有效数字
*/

int main() {
	//单精度float
	float 	flt = 3.1415926f;
	//双精度double
	double	dbe = 3.1415926;
	cout << "flt= " << flt <<endl;
	cout << "dbe= " << dbe <<endl;
	//c++ cout显示6位有效数字
	
	//sizeof内存空间：
	cout << "sizeof(float)="  << sizeof(float)  << "\t\tsizeof(flt)=" << sizeof(flt) << endl;
	cout << "sizeof(double)=" << sizeof(double) << "\tsizeof(dbe)=" << sizeof(dbe) << endl;

	//科学计数法
	float	flt2 = 3e2f;
	cout << "flt2=" << flt2 << endl;
	double	dbe2 = 3e-2f;
	cout << "dbe2=" << dbe2 << endl;
	
	return 0;
}
