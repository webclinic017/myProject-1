#include "199person.h"

#include <set>

/*
教师类的设计
*/
class Teacher : public Person {
public:
	int teacher_id;
public:
	// 默认构造
	Teacher();

	// 有参构造
	Teacher(int t_id, string t_name, string t_password);

	// 显示菜单
	virtual void openMenu();

	// 查看所有预约
	void showAllOrder();

	// 审核预约
	void validOrder();

};
