#include "107manager.h"

Manager::Manager(int id, string name, int department_id) {
	this->id = id; this->name = name; this->department_id = department_id;
};

void Manager::showInfo() {
	cout << "员工编号：" << this->id << "\t\t";
	cout << "员工姓名：" << this->name << "\t\t";
	cout << "员工部门：" << this->getDepartmentName() << "\t\t";
	cout << "岗位职责：" << this->getDuty() << endl;
};

string Manager::getDepartmentName() {
	return "管理部门";
};

string Manager::getDuty() {
	return "完成老板安排的任务，管理基层员工";
};
