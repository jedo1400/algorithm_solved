#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>

#define INTS int, int, int, int, int

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int result[4];
    deque<bool> rewarded(n+1);
    vector<pair<int, int>> nl, en, mt, sc;
    // 학번, 과목점수


    for (int i{}; i < n; ++i) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        nl.push_back({a, b});
        en.push_back({a, c});
        mt.push_back({a, d});
        sc.push_back({a, e});
    }

    sort(nl.begin(), nl.end(), cmp);
    sort(en.begin(), en.end(), cmp);
    sort(mt.begin(), mt.end(), cmp);
    sort(sc.begin(), sc.end(), cmp);

    for (auto &i : nl)
        if (!rewarded[i.first]) {
            result[0] = i.first, rewarded[i.first] = 1;
            break;
        }
    
    for (auto &i : en) 
        if (!rewarded[i.first]) {
            result[1] = i.first, rewarded[i.first] = 1;
            break;
        }

    for (auto &i : mt) 
        if (!rewarded[i.first]) {
            result[2] = i.first, rewarded[i.first] = 1;
            break;
        }

    for (auto &i : sc) 
        if (!rewarded[i.first]) {
            result[3] = i.first, rewarded[i.first] = 1;
            break;
        }
            
    cout << result[0] << ' ' << result[1] << ' ' << result[2] << ' ' << result[3];
}