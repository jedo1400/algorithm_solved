#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, n;
    cin >> d >> n;
    vector<int> oven(d);
    deque<bool> used(d, 0);

    for (int i{}; i < d; ++i) {
        cin >> oven[i];
        if (i && oven[i-1] < oven[i])
            oven[i] = oven[i-1]; // V자
    }
    
    int shallowest = d;
    bool full{};
    while (n--) {
        int m;
        cin >> m;

        if ((!shallowest && used[0]) || oven[0] < m)
            full = 1;
        
        else
            for (int i = shallowest-1; i >= 0; --i)
                if (!used[i] && oven[i] >= m) {
                    used[i] = 1, shallowest = i;
                    break;
                }
    }

    cout << (full ? 0 : shallowest+1);
}