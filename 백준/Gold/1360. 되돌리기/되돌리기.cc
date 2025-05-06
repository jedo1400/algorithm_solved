#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<string, int>> snapshot;
    snapshot.emplace_back("", 0);

    while (n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "type") {
            string c;
            int t;
            cin >> c >> t;
            snapshot.emplace_back(snapshot.back().first + c, t);
        }

        else {
            int s, e;
            cin >> s >> e;
            s = e-s;
            bool comp = 0;
            for (int i = snapshot.size()-1; i >= 0; --i) {
                auto &[str, t] = snapshot[i];
                if (t < s) {
                    snapshot.emplace_back(str, e);
                    comp = 1;
                    break;
                }
            }

            if (!comp)
                snapshot.emplace_back("", e);
        }
    }

    cout << snapshot.back().first;
}