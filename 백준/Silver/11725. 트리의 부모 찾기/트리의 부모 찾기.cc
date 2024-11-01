#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void getParent(vector<vector<int>> &array, vector<int> &parent, int n = 1) {
    static deque<bool> visited(array.size(), 0);

    visited[n] = 1;

    if (array[n].empty())
        return;
    
    for (auto &i : array[n]) {
        if (!visited[i]) {
            parent[i] = n;
            getParent(array, parent, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> array(n+1, vector<int>());
    vector<int> parent(n+1);

    for (int i{}; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        array[a].push_back(b);
        array[b].push_back(a);
    }

    getParent(array, parent);

    for (int i = 2; i <= n; ++i)
        cout << parent[i] << '\n';
}
