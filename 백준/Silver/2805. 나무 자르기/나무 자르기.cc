#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, largest{};
    cin >> n >> m;
    vector<int> trees(n);

    for (auto &i : trees) {
        cin >> i;
        if (i > largest)
            largest = i;
    }

    int h{}, start = 0, end = largest;
    while (end-start) {
        int mid = (end+start) / 2;
        long long sum{}; // INT_MAX*10억

        for (auto &i : trees)
            if (i > mid)
                sum += i-mid;
        
        if (h == mid)
            break;
        
        if (m < sum) // 잘라야하는 나무 길이보다 합이 크다면
            h = mid, start = mid;
        else if (m > sum)
            h = mid, end = mid;
        else {
            h = mid;
            break;
        }
    }

    cout << h;
}
