#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n;
    cin >> n;
    vector<short> array(n);

    for (short i = 0; i < n; ++i)
        cin >> array[i];
    
    sort(array.begin(), array.end());

    int time{}, rst{};
    for (auto &i : array)
        time += i, rst += time;
    
    cout << rst;
}