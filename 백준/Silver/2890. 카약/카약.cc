#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

bool cmpf(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

bool cmps(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r, c;
    cin >> r >> c;
    vector<pair<int, int>> list, sorted;

    for (int i{}; i < r; ++i) {
        string map;
        cin >> map;

        int j{};
        while ((map[j] < 48 || map[j] > 57) && j < map.length())
            ++j;
        
        if (j == map.length()) // 빈 줄 스킵
            continue;
        
        list.push_back({map[j]-48, j});
    }

    sorted = list;
    sort(list.begin(), list.end(), cmpf);
    sort(sorted.begin(), sorted.end(), cmps); // 많이 비효율적인 구현임
    
    int before = 50, tier = 0;
    unordered_map<int, int> rank; 

    for (auto &i : sorted)
        rank[i.second] = before != i.second ? ++tier : tier
        , before = i.second;

    for (auto &i : list)
        cout << rank[i.second] << '\n';
}