#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ll> array(20); // 20! == 2,432,902,008,176,640,000
    array[0] = 1, array[1] = 1;

    ll n, fact = 121645100408832000;
    cin >> n;
    
    for (short i = 19; i >= 0 && n >= 0; --i) {
        if (n >= fact) {
            n -= fact;
            if (!n) {
                cout << "YES";
                return 0;
            }
        }

        if (i) fact /= i;
    }

    cout << "NO";
}