#include <iostream>
using namespace std;

//None
//2
//3
class Student {
public:
	int id;

	Student() {
		id = 0;
		cout << "Student()" << endl;
	}

	Student(int _id) {
		id = _id;
	}

	Student(const Student& s) {
		id = s.id;
		cout << "Student(const Student & s)" << endl;
	}
};

void test1() {
	Student s1 = Student();
	Student s2 = Student(s1);

	cout << s1.id << endl;
	cout << s2.id << endl;
}

void test2() {
	Student s1 = Student(18);
	Student s2 = Student(s1);

	cout << s1.id << endl;
	cout << s2.id << endl;
}

int main() {
	test1();
	test2();
}
