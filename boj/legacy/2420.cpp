#include <iostream>

using namespace std;

long long self_made_abs(long long a) {
    return (a > 0 ? a : -a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    cout << self_made_abs((long long)n-m);
}