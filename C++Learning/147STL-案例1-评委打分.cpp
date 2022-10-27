#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
/*

*/
class Person {
public:
	string name;
	float score;
	Person(string name) {
		this->name = name;
		this->score = 0.0;
	};
	void showScore() {
		cout << "选手：" << this->name << ",  平均分：" << this->score << "。" << endl;
	};
};

int main() {
	// 1.创建五名选手
	vector<Person> v;
	v.push_back(Person("A")); // 零时对象也可以
	v.push_back(Person("B"));
	v.push_back(Person("C"));
	v.push_back(Person("D"));
	v.push_back(Person("E"));

	// 2.给5名选手打分
	deque<float> d;		// 创建计分器
	float tmp_score;	// 创建打分器（临时）
	float sum;			// 总分
	for (int i = 0; i < v.size(); i++) {
		// 清空、初始化
		d.clear(); tmp_score = 0.0; sum = 0.0;
		// 打分
		cout << "请给选手" << v[i].name << "打分：" << endl;
		for (int j = 1; j <= 10; j++) {
			cout << "第" << j << "位评委请打分：";
			cin >> tmp_score;
			d.push_back(tmp_score);
		};
		// 排序(去掉一个最低分一个最高分)
		sort(d.begin(),d.end()); d.pop_front(); d.pop_back(); 
		// 总分
		for (int k = 0; k < d.size(); k++) { sum += d[k]; };
		cout << "总分：" << sum << endl;
		// 记录平均分
		v[i].score = sum / d.size();
	};

	// 3.显示最后得分
	for (int i = 0; i < v.size(); i++) {
		v[i].showScore();
	};
	return 0;
}
