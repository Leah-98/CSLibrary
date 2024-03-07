#include <iostream>
using namespace std;

union info {
	char gender;
	int age;
	double score;
};

int main() {
	info a;//初始化时只能赋值一个变量。
	cout << sizeof(a) << endl;
	a.gender = 'F';
	cout << a.gender << endl;
	a.age = 18;
	cout << a.age << endl;
	cout << a.gender << endl;//取不到了
	a.score = 95.5;
	cout << a.score << endl;
}
