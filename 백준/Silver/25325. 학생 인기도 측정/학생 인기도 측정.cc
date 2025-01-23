#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<string, int> popularity;
    string vote, str_buff;

    int n;
    cin >> n;
    cin.ignore();

    getline(cin, vote);
    istringstream ss(vote);
    while (getline(ss, str_buff, ' '))
        popularity[str_buff] = 0; // 투표되지 않은 후보도 출력해야함

    while (n--) {
        vector<string> name;

        getline(cin, vote);
        istringstream ss(vote);

        while (getline(ss, str_buff, ' '))
            name.push_back(str_buff);

        for (auto &i : name)
            ++popularity[i];
    }

    vector<pair<string, int>> result;
    for (auto &i : popularity)
        result.push_back({i.first, i.second});
    
    sort(result.begin(), result.end(), [](pair<string, int> &a, pair<string, int> &b) -> bool {
       if (a.second == b.second) return a.first < b.first;
       return a.second > b.second;
    });

    for (auto &i : result)
        cout << i.first << ' ' << i.second << '\n';
}