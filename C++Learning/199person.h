#pragma once
#include <iostream>
using namespace std;
#include "199orderFile.cpp"
/*
创建身份基类：
	所有身份都有的共同属性（用户名、密码）把他抽象到这个基类当中
	对于每个身份的菜单函数，我们用一个纯虚函数。然后子类重写这个纯虚函数实现多态。
*/

class Person {
public:
	string name; // 用户名
	string password; // 密码
public:
	virtual void openMenu() = 0; // 身份子菜单
};
