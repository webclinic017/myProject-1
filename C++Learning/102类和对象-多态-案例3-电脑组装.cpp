#include <iostream>
using namespace std;
/*

*/
class CPU {
public:
	virtual void calculate() = 0;
};
class MEMORY {
public:
	virtual void save() = 0;
};
class GPU {
public:
	virtual void display() = 0;
};

class PC {
public:
	CPU * cpu;
	MEMORY * memory;
	GPU * gpu;
	
	PC(CPU * cpu, MEMORY * memory, GPU * gpu) {
		this->cpu = cpu;
		this->memory = memory;
		this->gpu = gpu;
	};

	void work() {
		cpu->calculate();
		memory->save();
		gpu->display();
	};
	~PC() {
		if (cpu != NULL)    {delete cpu;    cpu = NULL;   };  
		if (memory != NULL) {delete memory; memory = NULL;};
		if (gpu != NULL)    {delete gpu;    gpu = NULL;   };
	};
};

class IntelCpu : public CPU {
public:
	void calculate() {
		cout << "intel的cpu开始计算" << endl;
	};
};
class IntelMemory : public MEMORY {
public:
	void save() {
		cout << "intel的内存开始存储" << endl;
	};
};
class IntelGpu : public GPU {
public:
	void display() {
		cout << "intel的显卡开始显示画面" << endl;
	};
};

class AMDCpu : public CPU {
public:
	void calculate() {
		cout << "AMD的cpu开始计算" << endl;
	};
};
class AMDMemory : public MEMORY {
public:
	void save() {
		cout << "AMD的内存开始存储" << endl;
	};
};
class AMDGpu : public GPU {
public:
	void display() {
		cout << "AMD的显卡开始显示画面" << endl;
	};
};


int main() {
	cout << "pc1:" << endl;
	PC pc1(new IntelCpu, new IntelMemory, new AMDGpu);
	pc1.work();

	cout << "pc2:" << endl;
	PC pc2(new IntelCpu, new AMDMemory, new IntelGpu);
	pc2.work();
	return 0;
}
