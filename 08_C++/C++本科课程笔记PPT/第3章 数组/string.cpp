#include<iostream>
using namespace std;

int main() {
    // char a[] = "jinan";
    // char b[] = "jinan";//ab地址不同

    string a = "jinan";
    string b = "jinan";

    if (a == b) {//ab字符内容相同
        cout << "true" << endl;
    }

    else {
        cout << "false" << endl;
    }
}
