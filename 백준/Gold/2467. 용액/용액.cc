#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define INF 1e9*2

vector<int> solution;

long _abs(long n) {
    return n > 0 ? n : -n;
}

pair<int, int> two_pointer() {
    int l = 0, r = solution.size()-1;
    long sum, min = INF*2;
    pair<int, int> result;

    while (l < r) {
        sum = _abs(solution[l] + solution[r]);

        if (sum < min)
            result = {solution[l], solution[r]}
            , min = sum;
            
        if (abs(solution[l]) < abs(solution[r]))
            --r;
        else
            ++l;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    solution.resize(n);

    for (auto &i : solution)
        cin >> i;

    auto [a, b] = two_pointer();
    cout << a << ' ' << b;
}
