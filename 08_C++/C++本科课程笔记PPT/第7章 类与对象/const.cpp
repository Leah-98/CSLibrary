#include <iostream>
using namespace std;

class Student {
public:
	int id;
	mutable int age;	//可变的
	const int hands;	//Cannot modify this variable
	//const int hands = 2;

	Student() : hands(2) {
		id = 1;
		age = 100;
	}

	//No modification in the function
	void modify1() const {
		// id = 100;//不能修改
		age = 18;//可以修改
		// hands = 1;
	}

	void modify2() {
		id = 100;
		age = 18;
	}
};

int main() {
	int a = 1;

	const int b = 1;
	// b = 2;//不能修改

	const int* c = &a;//常量指针，常量本身不能被修改，指针可以修改
	// *c = 2;
	c = &b;

	int* const d = &a;//指针常量，指针本身不能被修改，常量可以修改
	// d = &b;
	*d = 2;

	const int* const e = &a;

	const int& f = a;//常量引用
	// f = 2;



	const Student s;
	// s.id = 100;//只能修改常量值
	s.age = 18;

	s.modify1();
	s.modify2();//一调用就出错

}
