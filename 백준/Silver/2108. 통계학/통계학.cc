#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n
        , sum = 0, median
        , smallest = INT_MAX, biggest = INT_MIN
        , biggest_count = INT_MIN;
    bool changed = 0;
    cin >> n;

    vector<short> array(n);
    set<int> mode;
    map<short, int> count;

    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        if (array[i] > biggest) biggest = array[i];
        if (array[i] < smallest) smallest = array[i];
        sum += array[i], ++count[array[i]];;
    }

    for (int i = 0; i < n; ++i)
        if (count[array[i]] >= biggest_count) {
            if (count[array[i]] > biggest_count)
                mode.clear();
            mode.insert(array[i]);
            biggest_count = count[array[i]];
        }
    
    sort(array.begin(), array.end());
    
    // for (auto i = mode.begin(); i != mode.end(); ++i)
    //     cout << *i << ' ';

    cout << ((int)((double)sum/n) == 0 && sum < 0 ? -1 : 1) * round((double)sum/n) << endl << array[n/2] << endl << (mode.size()-1 ? *(++mode.begin()) : *mode.begin()) << endl << biggest-smallest;
}