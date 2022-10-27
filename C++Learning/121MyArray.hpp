#pragma once
#include <iostream>
using namespace std;
/*

*/
template<typename T>
class myArr {
private:
	// 数组地址
	T * address = NULL;
	// 数组容量
	int capacity = 0;
	
	// 数组size大小
	int size = 0;
public:
	// 有参构造
	myArr(int num) {
		this->address = new T[num];
		this->capacity = num;
		this->size = 0;
	};

	// copy构造
	myArr(const myArr &p) {  // 传入的是一个实例对象，而不是模板
		this->capacity = p.capacity;
		this->size = p.size;
		this->address = new T[this->capacity];
		for (int i=0; i<this->capacity; i++) {
			this->address[i] = p.address[i];
		};
	};

	// 析构函数
	~myArr() {
		if (this->address != NULL) {
			delete[] this->address;
			this->address = NULL;
		};
	};

	// opreate=函数
	myArr& operator= (const myArr &p) {
		// 注意：用oprerator=函数时，原this可能是有数据的，必须先删除。
		if (this->address != NULL) {
			this->capacity = 0;
			this->size = 0;
			delete[] this->address;
			this->address = NULL;
		};
		// 再copy
		this->capacity = p.capacity;
		this->size = p.size;
		this->address = new T[this->capacity];
		for (int i=0; i<this->capacity; i++) {
			this->address[i] = p.address[i];
		};
		return *this;
	};

	void findByIdx(int idx) {
		if (this->capacity == 0) {cout << "数组为空！" << endl;return;}
		if (idx >= 0 and idx < this->capacity) {
			cout << "找到下标" << idx << "的数字为：" << this->address[idx] << endl; 
		}
		else {
			cout << "请输入正确的下标" << endl;
		}
	};

	void insert(T element) {
		T * newAddress = new T[capacity+1];
		for (int i=0; i < capacity; i++) {
			newAddress[i] = address[i];
		};
		newAddress[capacity] = element;
		delete[] address;
		address = newAddress;
		newAddress = NULL;
		this->capacity++;
	};

	void backspace() {
		T * newAddress = new T[capacity-1];
		for (int i=0; i < capacity-1; i++) {
			newAddress[i] = address[i];
		};
		delete[] address;
		address = newAddress;
		newAddress = NULL;
		this->capacity--;

	};

	void getCapacity() {
		cout << "容量：" << this->capacity << endl;
	};

	void getSize() {
		this->size = sizeof(address)/sizeof(address[0]);
		cout << "Size：" << this->size << endl;
	}

	void showArr() {
		for (int i=0; i < capacity; i++) {
			cout << address[i] << endl;
		};
	};

	void func() {
		address[0] = 1;
		address[1] = 2;
		address[2] = 3;
	}


};



