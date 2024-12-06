#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isGather(char c) {
    static char gather[] = { 'a', 'e', 'i', 'o', 'u' };
    for (int i{}; i < 5; ++i)
        if (c == gather[i])
            return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    while (1) {
        cin >> str;
        if (str == "end")
            break;

        bool flag = 1;

        bool has_gather = 0;
        for (auto &i : str) // 모음을 포함하였는가
            if (isGather(i)) {
                has_gather = 1;
                break;
            }
        if (!has_gather) flag = 0;
        
        // length 함수가 부호없는 값을 반환하는 듯
        for (int i{}; i < (int)str.length()-2; ++i) { // 모음이 3개, 혹은 자음이 3개 연속하는가
            int sum = isGather(str[i]) + isGather(str[i+1]) + isGather(str[i+2]);
            if (!sum || sum == 3) {
                flag = 0;
                break;
            }
        }

        for (int i{}; i < (int)str.length()-1; ++i) // 같은 글자 2개 이상 연속하는가
            if (str[i] == str[i+1] && str[i] != 'e' && str[i] != 'o') {
                flag = 0;
                break;
            }
        
        cout << '<' << str << "> is " << (flag ? "acceptable." : "not acceptable.") << '\n';
    }
}