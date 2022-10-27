#include "107boss.h"

Boss::Boss(int id, string name, int department_id) {
	this->id = id; this->name = name; this->department_id = department_id;
};

void Boss::showInfo() {
	cout << "员工编号：" << this->id << "\t\t";
	cout << "员工姓名：" << this->name << "\t\t";
	cout << "员工部门：" << this->getDepartmentName() << "\t\t";
	cout << "岗位职责：" << this->getDuty() << endl;
};

string Boss::getDepartmentName() {
	return "公司老板";
};

string Boss::getDuty() {
	return "统筹公司运作";
};
