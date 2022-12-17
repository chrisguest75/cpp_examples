#include <iostream>

using namespace std;
extern "C" char *get_version();
extern "C" char *get_message();

int main()
{
    cout << "Hello World from CPP" << endl;    
    cout << get_message() << endl;    
    cout << get_version() << endl;    
}

