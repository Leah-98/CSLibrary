#include<iostream>
using namespace std;

int iteration(int a) {
    int sum;

    for (sum = 1; a > 0; --a) {
        sum *= a;
    }

    return sum;
}

int recursion(int a) {
    if (a == 1) {
        return 1;
    }

    return a * recursion(a - 1);
}

int add(int a, int b) {
    return a + b;
}

float add(float a, float b = 3.3f) {
    return a + b;
}

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;

    cout << "In swap():  (a, b) = (" << a << ", " << b << ")" << endl;
}

void swap(int c[]) {
    int t = c[0];
    c[0] = c[1];
    c[1] = t;

    cout << "In swap():  (c[0], c[1]) = (" << c[0] << ", " << c[1] << ")" << endl;
    cout << "In swap():  size(c) = " << sizeof(c) << endl;//传进函数的是指针，值为4
}

int main() {
    cout << iteration(5) << endl;
    cout << recursion(5) << endl;

    cout << add(1, 2) << endl;
    cout << add(1.1f, 2.2f) << endl;
    // cout << add(1.1, 2.2) << endl;//不加f后缀，默认为double，不能使用add方法
    cout << add(1.1f) << endl;

    int a = 2, b = 4;
    swap(a, b);
    cout << "Out swap(): (a, b) = (" << a << ", " << b << ")" << endl;

    int c[] = { 2, 4 };
    swap(c);
    cout << "Out swap(): (c[0], c[1]) = (" << c[0] << ", " << c[1] << ")" << endl;
    cout << "Out swap(): size(c) = " << sizeof(c) << endl;//得到数组的长度，值为8
}
