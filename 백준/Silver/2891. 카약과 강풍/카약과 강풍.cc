#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s, r, result{};
    cin >> n >> s >> r;
    deque<bool> broken(n, 0);

    while (s--) {
        int m;
        cin >> m;
        broken[m-1] = 1, ++result;
    }

    vector<int> waitlist;
    while (r--) { // 내꺼
        int m;
        cin >> m;
        --m;

        if (broken[m])
            broken[m] = 0, --result;
        else
            waitlist.push_back(m);
    }

    for (auto &i : waitlist) { // 남한테 빌려주기
        if (i-1 >= 0 && broken[i-1])
            broken[i-1] = 0, --result;
        else if (i+1 < n && broken[i+1])
            broken[i+1] = 0, --result;
    }

    cout << result;
}