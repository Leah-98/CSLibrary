#include <iostream>
using namespace std;

int main()
{
	int x = 1;
	int y = 2;
	int z = 3;
	cout << (x = y) << endl;//赋值x=y 输出x
	cout << (x == y) << endl;//判断得结果
	cout << ('a' == 97) << endl;//判断得结果
	cout << "a = " << x+++y << endl;//(x++)+y即2+2=4
}
