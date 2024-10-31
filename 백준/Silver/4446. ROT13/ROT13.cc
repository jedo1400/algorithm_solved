#include <iostream>
#include <string>

using namespace std;

string ROT13(string str) {
    static string vowel = "aiyeou";
    static string cons = "bkxznhdcwgpvjqtsrlmf";

    for (auto &i : str) {
        bool comp{}, uppercase = i >= 65 && i <= 90;
        char normalized = uppercase ? i+32 : i;

        for (short j = 0; j < vowel.length(); ++j)
            if (normalized == vowel[j]) {
                i = vowel[(j+3) % vowel.length()], comp = 1;
                break;
            }
        
        for (short j = 0; j < cons.length() && !comp; ++j)
            if (normalized == cons[j]) {
                i = cons[(j+10) % cons.length()];
                break;
            }
        
        if (uppercase)
            i -= 32;
    }

    return str;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string str;

    while (getline(cin, str))
        cout << ROT13(str) << '\n';
}