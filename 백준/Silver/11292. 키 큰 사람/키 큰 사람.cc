#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n && n) {
        vector<string> people;
        int tallest{};

        while (n--) {
            string name;
            float height_f;
            int height;
            cin >> name >> height_f;
            height = (int)(height_f * 100);

            if (height > tallest) {
                tallest = height;
                people.clear();
            }
            
            if (height >= tallest)
                people.push_back(name);
        }
        
        for (auto &i : people)
            cout << i << ' ';
        cout << '\n';
    }
}