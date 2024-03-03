#include <iostream>
using namespace std;

int add(int x, int y) {
    return x + y;
}

int mul(int x, int y) {
    return x * y;
}

int main()
{
    int a = 1;
    int* p1 = &a;
    //int a = 1, *p = &a;

    cout << p1 << endl;
    cout << &a << endl; //equal to the address of a
    cout << *p1 << endl; //equal to the a

    cout << &(*p1) << endl;//进行了两次逆操作，得到的还是p1
    cout << *(&a) << endl;//进行了两次逆操作，得到的还是a

    int* p2 = NULL;
    p2 = p1;
    int** p3 = &p2;

    cout << p2 << endl;//p2的内容即p1的内容即a的地址
    cout << &p2 << endl;//p2的地址
    cout << p3 << endl;//p3的内容即p2的地址
    cout << *p3 << endl;//p3的内容取内容，得到p1的地址即a的地址

    int b[] = { 1, 2, 3, 4, 5 };
    // int* p4 = b;
    int* p4 = &b[0];
    cout << b << endl;
    cout << b[2] << endl;
    cout << *(b + 2) << endl;
    cout << *(++p4) << endl;
    cout << *(p4++) << endl;
    cout << *(p4 - 2) << endl;

    int c[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    int(*p6)[2] = c;

    int* p5[3] = { c[0], c[1], c[2] };
    int** p7 = p5;

    int* p8 = &c[0][0];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << p8[i * 2 + j];
        }
    }
    cout << endl;

    int (*f)(int, int);
    f = add;
    //f = &add;
    cout << f(2, 3) << endl;
    //cout << (*f)(2, 3) << endl;
    f = mul;
    cout << f(2, 3) << endl;
}
