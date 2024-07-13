#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

bool desc(const short &a, const short &b) {
    return a > b ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short k;
    cin >> k;
    for (short i = 0; i < k; ++i) {
        short n, max = SHRT_MIN, min = SHRT_MAX, l_gap = 0;
        cin >> n;
        vector<short> array(n);

        for (short i = 0; i < n; ++i) {
            cin >> array[i];
            if (max < array[i]) max = array[i];
            if (min > array[i]) min = array[i];
        }
        
        sort(array.begin(), array.end(), desc);

        for (short i = 1; i < n; ++i)
            if (l_gap < array[i-1] - array[i])
                l_gap = array[i-1] - array[i];
        
        cout << "Class " << i+1 << '\n'
        << "Max " << max << ", Min " << min << ", Largest gap " << l_gap << '\n';
    }
}