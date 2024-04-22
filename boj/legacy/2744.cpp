#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n;
    char rst[101];
    cin >> n;

    for (short i = 0; i < n.length(); ++i)
        if (n[i] < 91)
            rst[i] = n[i]+32;
        else
            rst[i] = n[i]-32;
    
    for (short i = 0; i < n.length(); ++i)
        cout << rst[i];

}