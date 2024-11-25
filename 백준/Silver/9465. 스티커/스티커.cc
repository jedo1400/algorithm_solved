#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> sticker(n+2, vector<int>(2, 0));

        for (int i{}; i < 2; ++i)
            for (int j = 2; j <= n+1; ++j)
                cin >> sticker[j][i];

        for (int i = 2; i <= n+1; ++i)
            sticker[i][0] += max(sticker[i-2][1], sticker[i-1][1])
            , sticker[i][1] += max(sticker[i-2][0], sticker[i-1][0]);
        
		cout << max(sticker.back()[0], sticker.back()[1]) << endl;
    }
}