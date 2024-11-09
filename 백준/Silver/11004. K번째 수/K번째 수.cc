#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> array(n);

    for (auto &i : array)
        cin >> i;

    sort(array.begin(), array.end());

    cout << array[k-1];
}