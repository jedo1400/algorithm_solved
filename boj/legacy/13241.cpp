#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << a*b/gcd(a, b);
}