#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int l, k, c;
vector<int> v;

int decision(int m) {
    int last = l, _c = c;

    for (int i = v.size()-1; i >= 0; --i) { // i == v.size()-1일 때 v[i+1] == l임
        // v[i+1] == before
        if (last - v[i] > m) { // 마지막으로 잘랐던 위치 - 현재 위치 > mid면 (자를 때가 되면)
            if (v[i + 1] - v[i] > m) // 구간간의 거리가 mid를 넘으면
                return 0;

            if (!_c--)
                return 0;

            last = v[i + 1]; 
        }
    }
    
    if (_c) // 기회가 남았다면
        last = v[0]; 

    if (last > m) // 나무 모퉁이~마지막으로 자른 곳
        return 0;

    return last;
}

int main() {
    cin >> l >> k >> c;
    set<int> tmp;

    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        tmp.insert(n);
    }

    tmp.insert(l);
    v = vector<int>(tmp.begin(), tmp.end());

    int left = 1, right = l, result;
    while (left <= right) {
        int mid = (left + right) / 2
            , d = decision(mid);
        
        if (!d)
            left = mid + 1;
        else 
            right = mid - 1
            , result = d; 
    }

    cout << left << ' ' << result;
}