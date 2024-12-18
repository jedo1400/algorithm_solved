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

    for (int i{}; i < n; ++i)
        if (array[i] < i+1) {
            cout << i+1;
            break;
        }
}