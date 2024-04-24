#include <iostream>
#include <string>
#include <deque>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string ps;
    deque<bool> stack;
    bool flag;

    do {
        flag = 0;
        stack.clear();
        getline(cin, ps);
        if (ps != ".") {
            for (int i = 0; i < ps.length() && !flag; ++i) {
                switch (ps[i]) {
                    case '(': 
                        stack.push_back(0); break;
                    case ')': 
                        if (stack.size() && !stack.back()) stack.pop_back();
                        else flag = 1;
                        break;
                    case '[':
                        stack.push_back(1); break;
                    case ']':
                        if (stack.size() && stack.back() == 1) stack.pop_back();
                        else flag = 1;
                }
            }
            cout << (!stack.size() && !flag ? "yes" : "no") << '\n';
        }
    } while (ps != ".");
}