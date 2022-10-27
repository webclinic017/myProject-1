#include <iostream>
using namespace std;
/*
struct 的默认访问权限是public
class  的默认访问权限是private
*/
struct Bank1 {
	unsigned long long account;

	void set_account() {
		account = 510111;
	};
};

class Bank2 {
	unsigned long long account;

	void set_account() {
		account = 510111;
	};
};


int main() {
	Bank1 b1;
	b1.account = 155;
	b1.set_account();

	Bank2 b2;
	// b2.account = 133; // error: ‘long long unsigned int Bank2::account’ is private within this context
	// b2.set_account(); // error: ‘void Bank2::set_account()’ 			   is private within this context
	
	return 0;
}
