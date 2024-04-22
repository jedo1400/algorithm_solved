#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    unordered_map<string, bool> result;
    int weight = 1;
    cin >> input;

    for (int weight = 1; weight <= input.length(); ++weight)
        for (int i = 0; i < input.length(); ++i)
            result[input.substr(i, weight)] = 1;

    // for (auto iter = result.begin(); iter != result.end(); ++iter)
    //     cout << "debug : " << iter->first << '\n';
    cout << result.size();
}