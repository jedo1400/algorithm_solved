#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    string str;
    queue<int> high, low;

    while (1) {
        cin >> n;
        if (!n)
            break;

        cin.ignore();
        getline(cin, str);
        
        if (str[4] == 'h') high.push(n);
        else if (str[4] == 'l') low.push(n);
        else {
            bool flag = 1;
            while (!high.empty()) {
                int top = high.front();
                high.pop();
                if (top <= n) {
                    flag = 0;
                    high = queue<int>();
                    break;
                }
            }

            if (flag)
                while (!low.empty()) {
                    int top = low.front();
                    low.pop();
                    if (top >= n) {
                        flag = 0;
                        low = queue<int>();
                        break;
                    }
                }
            else
                low = queue<int>();
            
            cout << (flag ? "Stan may be honest" : "Stan is dishonest") << '\n';
        }
    }
}