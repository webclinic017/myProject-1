#include "107employee.h"

Employee::Employee(int id, string name, int department_id) {
	this->id = id; this->name = name; this->department_id = department_id;
};

void Employee::showInfo() {
	cout << "员工编号：" << this->id << "\t\t";
	cout << "员工姓名：" << this->name << "\t\t";
	cout << "员工部门：" << this->getDepartmentName() << "\t\t";
	cout << "岗位职责：" << this->getDuty() << endl;
};

string Employee::getDepartmentName() {
	return "基层职能部门";
};

string Employee::getDuty() {
	return "完成经理安排的任务";
};
