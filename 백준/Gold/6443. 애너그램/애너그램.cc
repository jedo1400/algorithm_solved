
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

void backtracking(string &str) {
    static deque<bool> visited(str.length(), 0);
    static vector<char> result;
    if (result.size() == str.length()) {
        for (auto &i : result)
            cout << i;
        cout << '\n';
        return;
    }

    deque<bool> visited_alphabet(26, 0); // 같은 위치에 올 수 있는 알파벳의 중복 검사
    
    for (int i{}; i < str.length(); ++i) {
        if (!visited[i] && !visited_alphabet[str[i]-97]) {
            visited[i] = 1;
            visited_alphabet[str[i]-97] = 1;
            result.push_back(str[i]);

            backtracking(str);

            visited[i] = 0;
            result.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    while (n--) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        
        backtracking(str);
    }
}