#include <iostream>
using namespace std;
/*
32位系统下 4bytes
64位系统下 8bytes
*/

int main() {
	int		a = 10;
	float	b = 10.01;
	double	c = 10.001;
	string	d = "10.0001";

	int		* A = &a;
	float 	* B = &b;
	double	* C = &c;
	string	* D = &d;

	cout << "A=" << A << endl;
	cout << "sizeof(A)=" << sizeof(A) << endl;
	cout << "B=" << B << endl;
	cout << "sizeof(B)=" << sizeof(B) << endl;
	cout << "C=" << C << endl;
	cout << "sizeof(C)=" << sizeof(C) << endl;
	cout << "D=" << D << endl;
	cout << "sizeof(D)=" << sizeof(D) << endl;



	return 0;
}
