#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (1) {
        string a;
        getline(cin, a);
        if (a == "#")
            break;
        
        bool array[26]{0,};
        for (auto &i : a)
            if (i >= 65 && i <= 90)
                array[i-65] = 1;
            else if (i >= 97 && i <= 122)
                array[i-97] = 1;
        
        short rst{};
        for (auto &i : array)
            if (i) ++rst;
        
        cout << rst << '\n';
    }
}