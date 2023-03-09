#include <iostream>
using namespace std;

class Student {
public:
	char color;
	static int n_eyes;

	Student() : color('b') {}

	void modify() {
		color = 'w';
		n_eyes = 10;
	}

	static void revise() {
		//color = 'r';
		n_eyes = 10;
	}
};

int Student::n_eyes = 2;

void main() {
	Student s;
	Student s1;

	Student::n_eyes = 5;
	//s.n_eyes = 5;
	cout << Student::n_eyes << endl;
	cout << s.n_eyes << endl;

	Student::revise();
	//s.revise();
	cout << Student::n_eyes << endl;
	cout << s.n_eyes << endl;

	s.modify();
	cout << s.color << endl;
	cout << s.n_eyes << endl;
	cout << s1.color << endl;
	cout << s1.n_eyes << endl;
}
