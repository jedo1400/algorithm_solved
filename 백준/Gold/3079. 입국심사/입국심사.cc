#include <algorithm>
#include <iostream>
#include <vector>

#define ull unsigned long long

using namespace std;

bool decision(vector<int> &arr, int m, ull t) {
    ull p{}; // 통과할 수 있는 사람의 수
    
    for (auto &i : arr)
        p += t / i; // mid / 검색대 별로 걸리는 시간 = 검색대가 t 내에 수용할 수 있는 최대한 많은 사람의 수
    
    return p >= m; // 만약 통과할 수 있는 사람의 수(p)가 m보다 많다면
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    ull l = 1, r{};
    cin >> n >> m;
    vector<int> way(n);

    for (auto &i : way) {
        cin >> i;
        r = max(r, (ull)i);
    }

    r *= m; // r(최댓값)은 가장 심사가 오래 걸리는 검색대를 친구 m명이 통과하는 경우에 걸리는 시간

    sort(way.begin(), way.end());

    while (l <= r) {
        ull mid = (l + r) / 2;

        if (decision(way, m, mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;
}