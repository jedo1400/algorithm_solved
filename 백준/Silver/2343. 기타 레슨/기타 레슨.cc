#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int decision(vector<int> &lecture, int size, int m) {
    int stack{}, bluray = 1;
    for (auto &i : lecture) {
        if (stack+i > size) // 만약 블루레이 용량이 다 찼다면
            stack = 0, ++bluray;

        stack += i;
    }

    return bluray;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> lecture(n);

    int l = 1, r{};
    for (auto &i : lecture) {
        cin >> i;
        r += i, l = max(l, i);
        // m이 1인 경우 모든 원소의 합이 답
        // l을 제대로 초기화하지 않으면 결정함수가 디스크가 담을 수 있는 용량보다 크기가 큰 영상을 담을 수 있음
    }
    
    // "블루레이의 개수를 가급적 줄이려고 한다"
    int min_bluray = m;
    while (l <= r) {
        int mid = (l + r) / 2
            , bluray = decision(lecture, mid, m);

        if (bluray <= m) // 만약 모두 넣을 수 있었다면
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;
}