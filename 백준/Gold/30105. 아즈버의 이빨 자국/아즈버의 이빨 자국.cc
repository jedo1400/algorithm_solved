#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX 4000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> mark(n), candidate;
    unordered_set<int> mask;

    int first = -1, largest = 0;
    for (auto &i : mark) {
        cin >> i;
        largest = max(largest, i);

        if (first != -1)
            candidate.push_back(i-first);
        else
            first = i;

        mask.insert(i);
    }

    vector<int> result;
    for (auto &i : candidate) {
        unordered_set<int> valid;

        for (auto &j : mark) {
            if (j+i > largest)
                break;
            
            if (mask.find(j+i) != mask.end()) {
                valid.insert(j+i);
                valid.insert(j);
            }
        }
        
        if (valid.size() == n)
            result.push_back(i);
    }

    cout << result.size() << '\n';
    for (auto &i : result)
        cout << i << ' ';
}