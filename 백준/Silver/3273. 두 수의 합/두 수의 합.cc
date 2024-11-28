#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, cnt=0;
    cin >> n;
    vector<int> array(n);
    deque<bool> visited(n, 0);

    for (auto &i : array)
        cin >> i;
    
    cin >> m;

    sort(array.begin(), array.end());

    int l = 0, r = n-1;
    while (r > l) {
        int sum = array[l] + array[r];
        if (sum == m)
            ++l, --r, ++cnt;
        
        else if (sum > m)
            --r;
        
        else
            ++l;
    }

    cout << cnt;
}