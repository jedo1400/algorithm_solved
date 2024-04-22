#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, tmp;
    cin >> n;
    map<int, int, greater<int>> array;
    vector<int> og_array(n);

    for (i = 0; i < n; ++i) {
        cin >> tmp;
        array[tmp] = 0;
        og_array[i] = tmp;
    }

    i = 0;
    for (auto iter = array.rbegin(); iter != array.rend(); ++iter, ++i)
        array[iter->first] = i;

    for (i = 0; i < og_array.size(); ++i)
        cout << array[og_array[i]] << ' ';
}