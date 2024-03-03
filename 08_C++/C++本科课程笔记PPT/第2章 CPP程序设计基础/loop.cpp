#include<iostream>
using namespace std;

int main() {

    int a = 0;

    // for (int i = 0; i < 3; ++i) {
    //    a += i;
    // }

    /*
    第一次循环
    i=0
    a=a+i=0+0=0
    第二次循环
    i=1(++i )
    a=a+i=0+1=1
    第三次循环
    i=2
    a=a+i=1+2=3
    */

    // int i = 0;
    // while (i <= 3) {
    //    a += i;
    //    ++i;
    // }//6

    // int i = 3;
    // do {
    //    a += i;
    //    --i;
    // } while (i > 3);//3

    // int i = 3;
    // while (i > 3) {
    //    a += i;
    //    --i;
    // }

    // for (int i = 0; i < 3; ++i) {
    //    for (int j = 1; j <= 3; ++j) {
    //        a += i * j;
    //    }
    // }//18

    // for (int i = 0; i < 3; ++i) {
    //    if (i == 1) {
    //        break;//退出循环
    //    }
    //    a += i;
    // }//0

    for (int i = 0; i < 3; ++i) {
        if (i == 1) {
            continue;
        }
        a += i;
    }//2



    cout << a << endl;
}
