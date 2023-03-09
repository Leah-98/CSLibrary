#include <iostream>
using namespace std;

void fun1(int x) {
    x = 2;
}

void fun2(int* x) {
    *x = 2;
}

void fun3(int& x) {
    x = 2;
}

int main()
{
    int a = 1;
    // fun1(a);
    // fun2(a);//不能传入
    fun3(a);//a的值被修改了
    //int& b;

    cout << a << endl;
}
