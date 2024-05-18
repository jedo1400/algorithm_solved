#include <iostream>

using namespace std;

short factorial(short n) {
    return (n <= 1 ? n : factorial(n-1)+factorial(n-2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    short n;
    cin >> n;
    cout << factorial(n);
}