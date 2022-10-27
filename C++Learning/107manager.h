#include "107worker.h"

class Manager : public Worker {
public:
	Manager(int id, string name, int department_id);
	void showInfo();			// 打信息
	string getDepartmentName();	// 获取部门名字
	string getDuty();				// 获取岗位职责
};
