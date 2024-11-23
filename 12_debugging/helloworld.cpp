#include <iostream>

using namespace std;

void input() {
    cout << "Please enter a number:" << endl;

    int number = 0;
    cin >> number;
    
    cout << "You entered " << number << endl;
}

int main(const int argc, const char **argv)
{
    cout << "Hello World" << endl;
    
    for (int i = 0; i < argc; i++)
    {
        cout << i << ": " << argv[i] << endl;
    }
}

