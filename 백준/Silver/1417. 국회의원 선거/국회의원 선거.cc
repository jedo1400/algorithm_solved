#include <iostream>
#include <vector>

using namespace std;

bool isDasomElected(vector<short>& candidate) {
    for (short i = 1; i < candidate.size(); ++i)
        if (candidate[0] <= candidate[i])
            return 0;
    return 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    short n, bought = 0;
    cin >> n;
    vector<short> candidate(n);

    for (short i = 0; i < n; ++i)
        cin >> candidate[i];

    while (!isDasomElected(candidate)) {
        pair<short, short> rival(0, 0);
        for (short i = 1; i < candidate.size(); ++i)
            if (candidate[i] > rival.first)
                rival = make_pair(candidate[i], i);
        --candidate[rival.second], ++candidate[0]
        , ++bought;
    }

    cout << bought;
}