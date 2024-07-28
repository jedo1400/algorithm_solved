#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (!n) { cout << 0; return 0; }
    vector<short> array(n);

    const int m = (n < 4 ? 0 : floor( ((float)n * 0.15) + 0.5 )); // 반올림

    for (int i{}; i < n; ++i)
        cin >> array[i];
    
    sort( array.begin(), array.end() );

    int result{}, i = m;
    while (true) {
        if (n-m == i)
            break;
        result += array[i], ++i;
    }

    cout << floor( (float)result/(n-m*2) + 0.5 );
}