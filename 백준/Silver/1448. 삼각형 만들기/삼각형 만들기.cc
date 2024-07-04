#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> array(1000001, 0);

    for (int i = 0; i < n; ++i) {
        cin >> m;
        ++array[m];
    }

    vector<int> array_s;

    for (int i = 1; i <= 1000000; ++i)
        while (array[i]) {
            array_s.push_back(i);
            --array[i];
        }
    
    int result = -1;

    for (int i = n-3; i >= 0; --i)
        if (array_s[i+2] < array_s[i+1] + array_s[i]) {
            result = array_s[i+2] + array_s[i+1] + array_s[i];
            break;
        }

    cout << result; 
}