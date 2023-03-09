#include <iostream>
using namespace std;

int main()
{
	cout << "2:    " << typeid(2).name() << endl;		//i
	cout << "2l:   " << typeid(2l).name() << endl;	//l
	cout << "2.0f: " << typeid(2.0f).name() << endl;//f
	cout << "2.0:  " << typeid(2.0).name() << endl;	//d

	char a = 'x';
	//char a = "x";
	cout << "a: " << a << endl;

	cout << ".145:     " << .145 << endl;			//0.145
	cout << "2.145E-1: " << 2.145E-1 << endl;	//10的-1次方 0.2145
	cout << "2.145e2:  " << 2.145e2 << endl;	//10的2次方 214.5

	//const int b = 1;
	//b = 2;
}
