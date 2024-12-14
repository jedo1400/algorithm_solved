#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void backtrack(vector<int> &array, int &m, int k = 0) {
    static deque<bool> visited(array.size(), 0);
    static vector<int> result(m);

    if (k == m) {
        for (auto &i : result)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    int before{};
    for (int i{}; i < array.size(); ++i)
        if (!visited[i] && before != array[i]) {
            result[k] = array[i]
            , visited[i] = 1
            , before = array[i];
            backtrack(array, m, k+1);
            visited[i] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> array(n);
    for (auto &i : array)
        cin >> i;

    sort(array.begin(), array.end());

    backtrack(array, m);
}