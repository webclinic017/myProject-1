#include <iostream>
using namespace std;


int main() {
	/*
	体重：int weight[5] = {300, 350, 200, 400, 250}
	找到最大值
	*/
	int weight[5] = {300, 350, 500, 400, 250};
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (weight[i] > max) {
			max = weight[i];
		}
	}
	cout << "最大体重：" << max << endl << endl;
	

	return 0;
}


