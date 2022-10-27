#include <iostream>
using namespace std;
/*
{"张飞",35};
{"赵云",32};
{"刘备",41};
{"黄忠",55};
{"关羽",39};
*/

struct hero {
	string name;
	int age;
};

void bubbleSort(struct hero arr[], int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len-1-i; j++) {
			if (arr[j].age < arr[j+1].age) {
				hero tmp_hero	=	arr[j];
				arr[j] 			= 	arr[j+1];
				arr[j+1] 		= 	tmp_hero;
			};
		};
	};
	cout << "武将年龄排名（从大到小）：" << endl;
	for (int k = 0; k < len; k++) {
		cout << arr[k].name << "	";
	};
	cout << endl;
};

int main() {
	hero heroArr[5] = {
		{"黄忠",55},
		{"关羽",39},
		{"张飞",35},
		{"赵云",32},
		{"刘备",41},
	};

	bubbleSort(heroArr, sizeof(heroArr)/sizeof(heroArr[0]));

	return 0;
}
