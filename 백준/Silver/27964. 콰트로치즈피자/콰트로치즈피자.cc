#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    set<string> cheese;
    
    cin >> n;

    while (n--) {
        string str;
        cin >> str;
        if (str.length() >= 6 && str.substr(str.length()-6) == "Cheese")
            cheese.insert(str);
    }
    
    cout << (cheese.size() >= 4 ? "yummy" : "sad");
}