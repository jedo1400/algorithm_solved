#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        string p, s;
        cin >> s >> p;

        int ptr{}, result{};

        while (ptr < s.length()) {
            int cnt{};
            for (int i{}; i < p.length() && i+ptr < s.length(); ++i)
                if (s[ptr+i] == p[i])
                    ++cnt;
            
            if (cnt == p.length())
                ptr += p.length();
            else
                ++ptr;
            
            ++result;
        }
        
        cout << result << '\n';
    }
}