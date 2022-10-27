#include <iostream>
using namespace std;
/*
public:		公共权限	成员在类内可以访问，类外也可访问
protected:	保护权限	成员在类内可以访问，类外不可以访问
private:	私有权限	成员在类内可以访问，类外不可以访问
*/

class People {
public:
	string name;

protected:
	string car;

private:
	int password;

public:
	void set_parm() {
		name = "张三";
		car  = "本田思域";
		password = 310323;
	};
};

int main() {
	People p1;
	p1.name = "李四";
	// p1.car = "丰田卡罗拉"; // 成员 "People::car" (已声明 所在行数:14) 不可访问C/C++(265)
	// p1.password = 310232; // 成员 "People::password" (已声明 所在行数:17) 不可访问C/C++(265)
	
	return 0;
}
