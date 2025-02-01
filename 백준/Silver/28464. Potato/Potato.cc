#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    deque<int> array(n);
    
    for (auto &i : array)
        cin >> i;
    
    sort(array.begin(), array.end());

    int p{}, s{};
    bool turn{}; // 0 = 박, 1 = 성우
    
    while (!array.empty()) {
        if (!turn) {
            p += array.back();
            array.pop_back();
        }
        
        else {
            s += array.front();
            array.pop_front();
        }

        turn = !turn;
    }

    cout << s << ' ' << p;
}