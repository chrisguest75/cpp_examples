#include <iostream>

using namespace std;

void divideByZero(int b) {
    cout << "divideByZero(b:" << b << ")" << endl;
    int a = 10 / b;
    cout << "a: " << a << endl;
}

void nullPointer(int *p) {
    cout << "nullPointer(p:" << p << ")" << endl;
    p[0] = 10;
}

int main()
{
    cout << "Welcome to the crasher application" << endl;
    cout << endl;

    //divideByZero(0);
    nullPointer(0);
}

