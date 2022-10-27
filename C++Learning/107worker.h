#pragma once
#include <iostream>

using namespace std;

class Worker {
public:
	int id;				// 编号
	string name;		// 名字
	int department_id;	// 部门编号
	virtual void showInfo() = 0;			// 打信息
	virtual string getDepartmentName() = 0;	// 获取部门名字
	virtual string getDuty() = 0;				// 获取岗位职责
};
