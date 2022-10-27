#include <iostream>
using namespace std;
/*
在类中有些私有属性，如果需要被类外的函数访问，就需要“友元”技术
*/
class Building {
// 友元声明：
friend void goodFriend(Building &b);
private:
	string bedroom;
public:
	string livingroom;
	Building() {
		bedroom = "卧室";
		livingroom = "起居室";
	}
};

void goodFriend(Building &b) {
	cout << "好朋友正在访问你的 " << b.livingroom << endl;
	cout << "好朋友正在访问你的 " << b.bedroom << endl;
};


int main() {
	Building b1;
	goodFriend(b1);
	return 0;
}
