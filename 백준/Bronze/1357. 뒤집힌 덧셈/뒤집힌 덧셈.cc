#include <iostream>

using namespace std;

short Rev(short n) {
    short len, result = 0;
    for (len = 1; (int)len*10 <= n; len *= 10)
        continue;
    
    for (short i = len, j = 1; i != 0; i /= 10, j *= 10)
        result += n/i * j, n %= i;

    return result;
}

int main() {
    short a, b;
    cin >> a >> b;
    cout << Rev(Rev(a)+Rev(b));
}