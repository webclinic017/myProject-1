#include <iostream>
using namespace std;
#include <set>
/*
set/multiset 插入数值会被自动排序(底层是二叉树);set插入重复的值会石沉大海,multiset可以插重复值。
*/
void printSet(const set<int> &s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	};
	cout << endl;
};
void printMultiSet(const multiset<int> &s) {
	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	};
	cout << endl;
};


int main() {
	set<int> s1;
	s1.insert(40); // set没有push和pop 只有insert
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(10);
	printSet(s1);
	// 拷贝构造
	set<int> s2(s1);
	printSet(s2);
	// operator=
	set<int> s3 = s2;
	printSet(s3);


	// multiset
	multiset<int> ms1;
	ms1.insert(40); // set没有push和pop 只有insert
	ms1.insert(10);
	ms1.insert(30);
	ms1.insert(20);
	ms1.insert(10);
	printMultiSet(ms1);
		// 拷贝构造
	multiset<int> ms2(ms1);
	printMultiSet(ms2);
	// operator=
	multiset<int> ms3 = ms2;
	printMultiSet(ms3);

	return 0;
}
