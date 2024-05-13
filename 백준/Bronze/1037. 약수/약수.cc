#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    short t;
    int n, biggest = 0, smallest = INT_MAX;
    cin >> t;
    
    for (short i = 0; i < t; ++i) {
        cin >> n;
        if (n > biggest) biggest = n;
        if (n < smallest) smallest = n;
    }

    cout << biggest * smallest;
}