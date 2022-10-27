#pragma once
#include <iostream>
using namespace std;

// 演讲选手类
class Speaker {
public:
	string name;
	double scoreArr[2]; //考虑到可能会有两轮的分数
};

// 计分器
class Counter {
public:
	int id;
	double score;
	Counter(int id, double score) {
		this->id = id; this->score = score;
	};
};