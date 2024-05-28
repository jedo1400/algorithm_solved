#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
    short n, k, t;
    cin >> n >> k;
    
    vector<short> array(n+1);
    array = {0,};
    short largest = SHRT_MIN;
    
    for (short i = 1; i <= n; ++i) {
        cin >> t;
        array[i] = t;
        if (i)
            array[i] += array[i-1];
    }

    for (short i = k; i <= n; ++i)
        if ((t = array[i] - array[i-k]) > largest)
            largest = t;

    cout << largest;
}