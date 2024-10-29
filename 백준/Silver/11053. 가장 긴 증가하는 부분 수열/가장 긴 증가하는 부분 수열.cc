#include <iostream>

using namespace std;

int main() {
    short n, longest = 1;
    short dp[1001] = {0,};
    cin >> n;
    
    while (n--) {
        short m;
        cin >> m;

        if (!dp[m])
            dp[m] = 1;

        for (short i = 1; i < m; ++i)
            if (dp[i]+1 > dp[m])
                dp[m] = dp[i]+1;
    }

    for (short i = 1; i <= 1000; ++i)
        if (dp[i] && longest < dp[i])
            longest = dp[i];
            
    cout << longest;
}