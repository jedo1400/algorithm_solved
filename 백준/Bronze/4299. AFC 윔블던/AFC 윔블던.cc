#include <iostream>

using namespace std;

int main() {
    short a, b, x, y;
    cin >> a >> b;
    x = (a+b)/2, y = a-x;
    if (a >= b && x+y == a && x-y == b)   
        cout << (a+b)/2 << ' ' << a-((a+b)/2);
    else
        cout << -1;
}