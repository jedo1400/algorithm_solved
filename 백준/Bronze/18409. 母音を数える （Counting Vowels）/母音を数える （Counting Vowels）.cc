#include <iostream>

using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, cnt = 0;
    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
    cin >> n;

    char* string = new char[n+1]; // NUL
    cin >> string;

    for (short i = 0; i < n; ++i)
        for (short j = 0; j < 5; ++j)
            if (string[i] == vowel[j])
                ++cnt;
    
    cout << cnt;
}