#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> f(n);

    for (auto &i : f)
        cin >> i;
    
    sort(f.begin(), f.end());

    long result{};
    for (int i = 0; i < n; ++i) {
        int start = i, end = n-1, j = i;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (f[i] >= (long)f[mid] * 0.9)
                start = mid+1, j = max(j, mid);
            else
                end = mid-1;
        }

        // 검사할 수 있는 것 중 가장 큰 파일의 인덱스(j) - 가장 작은 파일(i)
        result += j-i;
    }

    cout << result;
}