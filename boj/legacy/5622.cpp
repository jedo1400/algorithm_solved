#include <iostream>
#include <map>

using namespace std;

int main () {
    map<char, short> dict;
    string input;
    unsigned short result = 0;

    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < ((i==6 || i==8) ? 4 : 3); j++)
        {
            if (i > 0)
            {
                dict.insert({(char)((i-1)*3 + 65 + j + (i > 6 ? 1 : 0)), i + 2});
            }
        }
    }
    cin >> input;
    
    for (short i=0; i < input.size(); i++)
    {
        result += dict[input[i]];
    }
    
    cout << result;
}