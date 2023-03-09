#include <iostream>
using namespace std;

class Person {
public:
	int age;
};

class Father {
public:
	int age;

	Father() : age(18) {}

	void show() {
		cout << "Father::show()" << endl;
	}

	//void show(int a) {
	//	cout << "Father::show(int a)" << endl;
	//}
};

class Son : public Father {
public:
	int age;

	Son() : age(28) {}

	void show() {
		cout << "Son::show()" << endl;
	}
};

//cl /d1 reportSingleClassLayout[class] file_name
void main() {
	Son s;

	cout << s.age << endl;
	cout << s.Father::age << endl;
	cout << s.Son::age << endl;

	s.show();
	s.Father::show();
	s.Son::show();

	//s.show(100);
	//s.Father::show(100);
}
