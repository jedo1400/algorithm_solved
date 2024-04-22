#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    short t;
    cin >> t;
    
    vector<short> r(t);
    vector<string> S(t);
    vector<string> result(t);
    for (short i = 0; i < t; ++i)
        cin >> r[i] >> S[i];
    
    for (short i = 0; i < t; ++i)
        for (short j = 0; j < S[i].size(); ++j)
            for (short k = 0; k < r[i]; ++k)
                result[i].push_back(S[i][j]);
    
    for (short i = 0; i < t; ++i)
        cout << result[i] << endl;
}