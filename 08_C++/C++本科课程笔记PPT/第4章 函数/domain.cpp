#include<iostream>
using namespace std;

int a = 1;
int b = 2;

void fun(int a) {
    cout << "fun(): a = " << a << endl;
    cout << "fun(): b = " << b << endl;
    // cout << "fun(): c = " << c << endl;//不能使用，定义在后面
}

int main() {
    int a = 3;
    cout << "main(): a = " << a << endl;

    fun(4);

    for (int i = 0; i < 1; ++i) {
        cout << "for(): a = " << a << endl;
    }

    // cout << "main(): i = " << i << endl;//不能使用，定义在循环体内
}

int c = 5;
