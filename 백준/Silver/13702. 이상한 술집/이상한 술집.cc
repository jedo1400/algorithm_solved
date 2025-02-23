#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool decision(vector<int> &v, int k, long long m) {
    long long p{};

    for (auto &i : v)
        p += i / m;

    return p >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> makgeolli(n);

    long long l = 1, r{};
    for (auto &i : makgeolli) {
        cin >> i;
        r = max(r, (long long)i);
    }

    while (l <= r) {
        long long mid = (l + r) / 2;
        
        if (decision(makgeolli, k, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    
    cout << r;
}