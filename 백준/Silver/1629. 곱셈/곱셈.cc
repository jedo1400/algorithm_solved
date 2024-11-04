#include <iostream>
#define ull unsigned long long

using namespace std;

ull eff_power(ull a, ull b, ull c) {
    if (b == 1)
        return a % c;

    ull m;
    if (b % 2) {
        m = eff_power(a, (b-1)/2, c) % c;
        return ((m*m%c)*(a % c)) % c;
    }
    else {
        m = eff_power(a, b/2, c) % c;
        return (m*m) % c;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    ull a, b, c;
    cin >> a >> b >> c;
    cout << eff_power(a, b, c);
}