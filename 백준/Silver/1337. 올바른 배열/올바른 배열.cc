#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> array(n);

    for (auto &i : array)
        cin >> i;

    sort(array.begin(), array.end());

    int result = 1;
    for (int i{}; i < n; ++i) {
        int continued = 1;
        bool exist[4] = {0,};

        for (int j = i+1, k{}; j < i+5 && j < n; ++j, ++k) 
            if (array[i] <= array[j] && array[j] <= array[i]+4)
                exist[array[j]-array[i]-1] = 1;
        
        for (int i{}; i < 4; ++i)
            if (exist[i])
                ++continued;

        result = max(result, continued);
    }

    cout << 5-result;
}