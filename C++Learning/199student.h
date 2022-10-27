#include "199person.h"
using namespace std;
#include "199computer.h"

#include <vector>
#include <fstream>
#include <set>

class Student : public Person {
public:
	int student_id; // 特有属性：学号
	// 机房容器
	vector<Computer> v_computer;
public:
	// 默认构造
	Student();

	// 有参构造
	Student(int s_id, string s_name, string s_password);

	// 打开菜单
	virtual void openMenu();

	// 申请预约
	void applyOrder();

	// 查看自己的预约
	void showMyOrder();

	// 查看所有预约
	void showAllOrder();

	// 取消预约
	void cancelOrder();	

	// 初始化机房容器
	void initComputer();
};
