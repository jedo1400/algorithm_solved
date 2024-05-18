#include <iostream>

using namespace std;

long long factorial(int n, long long m = 1) {
    return (n <= 1 ? m : factorial(n-1, m * n));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    cout << factorial(n);
}