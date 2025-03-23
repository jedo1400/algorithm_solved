#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define INF (unsigned int)(1 << 31) - 1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c, n;
    cin >> c >> n;
    vector<pair<int, int>> city(n);

    for (auto &i : city)
        cin >> i.first >> i.second;
    
	// 홍보효과는 분할할 수 없기때문에 딱 c명만큼의 잠재고객을 확보하는 방법은 존재하지 않을 수 있음
	// 둘째 줄부터 N개의 줄에는 각 도시에서 홍보할 때 대는 비용과 그 비용으로 얻을 수 있는 고객의 수가 주어진다. 이 값은 100보다 작거나 같은 자연수이다.
    vector<int> dp(c + 101, INF);
    dp[0] = 0;

    for (auto &[w, v] : city)
        for (int j = v; j < dp.size(); ++j)
			if (dp[j-v] != INF)
            	dp[j] = min(dp[j], dp[j-v] + w);

    cout << *min_element(dp.begin() + c, dp.end());
}