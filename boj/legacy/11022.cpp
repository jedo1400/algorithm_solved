#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    short temp;

    cin >> t;
    short* result = new short[t]{};
    vector<vector<short>> param(t, vector<short>(2));

    for (int i = 0; i < t; ++i)
        for (short j = 0; j < 2; ++j) {
            cin >> temp;
            param[i][j] = temp
            , result[i] += temp;
        }
    for (int i = 0; i < t; ++i)
        cout << "Case #" << i+1 << ": " << param[i][0] << " + " << param[i][1] << " = " << result[i] << "\n";
}