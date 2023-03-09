#include <iostream>
using namespace std;

int main()
{
	int a = 3.6;
	float b = 5 / 2;	//看除数，强制转换为int
	int c = 5 % 2;		//1
	float d = 5 / 2.0;//2.5
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	int e = 1;
	int f = (++e) * 2;
	cout << "e = " << e << endl;
	cout << "f = " << f << endl;

	int g = 1;
	int h = (g++) * 2;
	cout << "g = " << g << endl;
	cout << "h = " << h << endl;

}
