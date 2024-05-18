#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string input;

    cin >> n >> m;

    unordered_map<string, int> first;

    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (input.length() >= m)
            ++first[input];
    }

    vector<pair<string, int>> word_count(first.begin(), first.end());

    sort(word_count.begin(), word_count.end(), cmp);

    for (auto& iter : word_count)
        cout << iter.first << '\n';
}