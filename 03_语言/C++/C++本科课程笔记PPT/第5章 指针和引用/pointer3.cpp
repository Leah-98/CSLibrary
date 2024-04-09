#include <iostream>
using namespace std;

int fun1(int x) {
	x += 2;
	return x;
}

int fun2(int x[]) {
	x[0] += 2;
	return *x;
}

int* fun3(int* p) {
	*p += 2;
	return p;
}

int* fun4(int x) {
	x += 2;
	int* p = &x;
	return p;
}

int main() {
	int a[3] = { 1, 2, 3 };
	int* b = a;
	int c = 0;

	// c = *(b + 1);
	// c = *b + 1;
	// c = *(++b);
	// c = *(b++);
	// c = ++(*b);
	c = (*b)++;

	cout << "(a[0], a[1], a[2]) = " << "(" << a[0] << ", " << a[1] << ", " << a[2] << ")" << endl;
	cout << "b = " << *b << endl;
	cout << "c = " << c << endl;


	int d = 1, e = 0, * f = NULL;
	// e = fun1(d);
	// e = fun2(&d);//相当于说，自身也会被修改
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;

	// f = fun3(&d);
	f = fun4(d);//因为func4返回的是局部变量的引用
	cout << "f = " << *f << endl;

}
