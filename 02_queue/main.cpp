#include <iostream>
#include <queue>

using namespace std;

int main(const int argc, const char **argv)
{
    queue<int> items;
    int number = -1;

    while (number != 0) {
        cout << "Please enter a number (0 to exit):" << endl;
        cin >> number;
        items.push(number);
    }

    //print queue
    while (!items.empty()) {
        cout << items.front() << ' ';
        items.pop();
    }

}