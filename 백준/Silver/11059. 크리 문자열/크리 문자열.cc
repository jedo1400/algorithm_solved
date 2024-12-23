#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    vector<int> prefix_sum(str.length(), 0);
    prefix_sum[0] = str[0] - 48;

    for (int i = 1; i < str.length(); ++i)
        prefix_sum[i] += prefix_sum[i-1] + str[i] - 48; 
    
    int result{};
    for (int i = str.length()/2; i; --i)
        for (int j = 0; j <= str.length()-i*2; ++j)
            if (prefix_sum[i+j-1]-(!j ? 0 : prefix_sum[j-1]) == prefix_sum[i*2+j-1]-prefix_sum[i+j-1])
                result = max(result, i*2);

    cout << result;
}