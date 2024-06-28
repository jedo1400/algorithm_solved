#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool desc(const short &a, const short &b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    int result = 0; // 100*100*100
    
    cin >> n;
    vector<short> a(n), b(n);

    for (short i = 0; i < n; ++i) cin >> a[i];
    for (short i = 0; i < n; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), desc);

    for (short i = 0; i < n; ++i)
        result += a[i]*b[i];

    cout << result;
    return 0;
}