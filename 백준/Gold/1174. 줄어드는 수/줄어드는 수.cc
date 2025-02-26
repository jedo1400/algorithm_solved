#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void backtracking(vector<long> &result, int size) {
    static vector<int> combi;
    static bool visited[10] = {0,};

    if (combi.size() == size) {
        long r{}; // 9,876,543,210

        for (auto &i : combi)
            r *= 10, r += i;
        
        result.push_back(r);
        return;
    }

    for (int i{}; i < 10; ++i)
        if (!visited[i] && (!combi.size() || i < combi.back())) {
            visited[i] = 1;
            combi.push_back(i);

            backtracking(result, size);

            visited[i] = 0;
            combi.pop_back();
        }
            
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<long> result;
    
    for (int i = 1; i <= 10; ++i)
        backtracking(result, i);

    int n;
    cin >> n;

    cout << (--n >= result.size() ? -1 : result[n]);
}