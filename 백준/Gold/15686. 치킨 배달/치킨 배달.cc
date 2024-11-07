#include <algorithm>
#include <iostream>
#include <limits.h>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

short abs(short &n) {
    return n < 0 ? n : -n;
}

short getChickenDistance(vector<pair<short, short>> &house, vector<pair<short, short>> &chicken, short &size) {
    vector<short> distance(house.size(), 50);
    for (auto &i : chicken)
        for (short j{}; j < house.size(); ++j) {
            short dist = abs(i.first-house[j].first) + abs(i.second-house[j].second);
            if (distance[j] > dist)
                distance[j] = dist;
        }
    
    short result{}; // 49*50^2=12250
    for (auto &i : distance)
        result += i;
    
    return result;
}

void backtracking(vector<pair<short, short>> &house // dfs
                , vector<pair<short, short>> &chicken
                , short size, short m, short &min_dist
                , short cnt = 0, short start = 0) {
    static vector<short> combi(m);

    if (cnt == m) {
        vector<pair<short, short>> selected;
        for (auto &i : combi)
            selected.push_back(chicken[i]);

        min_dist = min(min_dist, getChickenDistance(house, selected, size));
        return;
    }
    
    for (short i = start; i < size; ++i) {
        combi[cnt] = i;
        backtracking(house, chicken, size, m, min_dist, cnt+1, i+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, m;
    cin >> n >> m;
    vector<pair<short, short>> chicken, house;

    for (short i{}; i < n; ++i)
        for (short j{}; j < n; ++j) {
            char input;
            cin >> input;
            if (input == '2')
                chicken.push_back({j, i}); // x, y
            else if (input == '1')
                house.push_back({j, i});
        }
    
    short result = SHRT_MAX;
    backtracking(house, chicken, chicken.size(), m, result);
    cout << result;
}