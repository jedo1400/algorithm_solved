#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<long> &decreasing, int depth) {
    static vector<int> num;
    static bool visited[10] = {0,};

    if (num.size() == depth) {
        long atoi{};
        
        for (auto &i : num)
            atoi *= 10
            , atoi += i;

        decreasing.push_back(atoi);
    }
    
    for (int i = 0; i <= 9; ++i) {
        if (!visited[i] && (!num.size() || i < num.back())) {
            num.push_back(i);
            visited[i] = 1;
            backtracking(decreasing, depth);
            num.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<long> decreasing;
    for (int i = 1; i <= 10; ++i) // 마지막 감소하는 수인 9876543210는 10자리
        backtracking(decreasing, i);
    
    int n;
    cin >> n;

    cout << (n >= decreasing.size() ? -1 : decreasing[n]);
}