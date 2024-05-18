#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<bool, int> recursion(const string &input, int l, int r, int cnt = 0) {
    if (l >= r) return make_pair(1, ++cnt);
    else if (input[l] != input[r]) return make_pair(0, ++cnt);
    else return recursion(input, l+1, r-1, ++cnt);
}

pair<bool, int> isPalindrome(const string &input) {
    return recursion(input, 0, input.length()-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    string input;
    cin >> n;
    while (n--) {
        cin >> input;
        pair<bool, int> result = isPalindrome(input);
        cout << result.first << ' ' << result.second << '\n';
    }
}