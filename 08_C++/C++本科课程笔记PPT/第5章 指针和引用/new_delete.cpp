#include <iostream>
using namespace std;

int fun1() {
    int a = 10;
    int b = a;

    return b;
}

int* fun2() {
    int a = 10;
    int* p = &a;

    return p;
}

int* fun3() {
    int* p = new int(10);

    return p;
}

int main()
{
    // int a = int(1);
    // int* p1 = new int(1);
    // int* p2 = new int[3];

    // delete p1;
    // delete[] p2;

    int a = fun1();
    int* p1 = fun2();
    int* p2 = fun3();

    cout << a << endl;
    cout << *p1 << endl;//居然还能用，很神奇
    cout << *p2 << endl;//这也能用


}
