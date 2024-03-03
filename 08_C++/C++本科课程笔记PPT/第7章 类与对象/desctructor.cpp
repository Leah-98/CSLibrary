#include <iostream>
using namespace std;

class Student {
public:
	int id;

	Student() {
		id = 0;
		//id = int(0);
		cout << "Student()" << endl;
	}

	~Student() {
		cout << "~Student()" << endl;
	}
};

class Teacher {
public:
	int* age;

	Teacher() {
		age = new int(0);
		cout << "Teacher()" << endl;
	}

	~Teacher() {
		//delete age;
		cout << "~Teacher()" << endl;
	}
};

int* test1() {
	Student s = Student();
	return &s.id;
}

int* test2() {
	Teacher t = Teacher();
	return t.age;
}

int main() {
	// test1();
	// Student s = Student();

	int* id = test1();
	int* age = test2();
	cout << *id << endl;//不知道为什么，全部看不到
	cout << *age << endl;//不知道为什么，全部看不到
}
