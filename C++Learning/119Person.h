#pragma once
#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Person {
public:
	T1 name;
	T2 age;
	Person(T1 name, T2 age);
	void show();
};
