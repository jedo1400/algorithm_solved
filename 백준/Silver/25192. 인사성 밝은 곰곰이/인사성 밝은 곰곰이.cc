#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int n, result = 0;
    cin >> n;
    set<string> log;
    
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (input == "ENTER")
            log.clear();
        else if (log.find(input) == log.end())
            log.insert(input), ++result;
    }
    cout << result;
}