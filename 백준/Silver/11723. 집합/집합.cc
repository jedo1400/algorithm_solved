

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool array[21]{0,};
    int m;
    cin >> m;
    
    cin.ignore();
    
    ++m;
    while (--m) {
        string cmd;
        getline(cin, cmd);

        switch (cmd[0]) {
            case 'a':
                if (cmd[1] == 'd') // add
                    array[stoi(cmd.substr(4))] = 1;
                
                else // all
                    for (short i = 1; i <= 20; ++i)
                        array[i] = 1;
                break;

            case 'c':
                cout << array[stoi(cmd.substr(6))] << '\n';
                break;

            case 't':
                array[stoi(cmd.substr(7))] = !array[stoi(cmd.substr(7))];
                break;
            
            case 'r':
                array[stoi(cmd.substr(6))] = 0;
                break;
            
            case 'e':
                for (short i = 1; i <= 20; ++i)
                    array[i] = 0;
        }
    }
}