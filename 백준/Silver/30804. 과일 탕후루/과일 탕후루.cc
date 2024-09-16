#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, count{};
    int type[10]{0,};
    cin >> n;
    vector<short> array(n);
    
    for (auto &i : array) {
        cin >> i;
        ++type[i];
    }

    int result{};
    for (short i = 1; i < 9; ++i)
        for (short j = i+1; j <= 9; ++j) {
            int longest{}, cur{};
            for (auto &k : array) {
                if (k == i || k == j) ++cur;
                else cur = 0;
                
                if (cur > longest) longest = cur;
            }
            if (longest > result) result = longest;
        }

    cout << result;
}