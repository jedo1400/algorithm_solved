#include <iostream>

using namespace std;

int main() {
    short n;
    int width = 2, weight = 1;
    cin >> n;

    for (short i = 0; i < n; ++i)
        width += weight, weight *= 2;
    
    cout << width*width;
}