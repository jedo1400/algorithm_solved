#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

int sol(vector<vector<int>> &v, int time = 0) {
    static bool visited[101][10]{0,};
    
    if (time > MAX)
        return time;

    int result = time;

    for (int i = time; i <= MAX; ++i)
        for (int j = 0; j < v[i].size(); ++j)
            if (!visited[i][j]) {
                visited[i][j] = 1;
                result = max(result, sol(v, time+v[i][j]));
                visited[i][j] = 0;
            }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        vector<vector<int>> food(MAX+1, vector<int>());
        
        while (n--) {
            int p, s;
            cin >> p >> s;
            food[p].push_back(s);
        }

        cout << "Case #" << i << ": " << sol(food) << '\n';
    }   
}