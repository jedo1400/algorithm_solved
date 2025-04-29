#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define LL long long
#define MAX 1000000000000000 // 10e15는 부동소수점 상수라 정확히 10^15가 아닐 수 있음

int main(){
    ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<LL> dp(100, MAX), segment(3);
	segment = {1, 10, 25}, dp[0] = 0;

	// {1, 10, 25}, {1*100, 10*100, 25*100}, {1*1000, 10*1000, 25*1000} ...
	/*
	....01
	....10
	....25
	..0100
	..1000
	..2500
	010000
	100000
	250000

	100단위로 나눠서 배낭문제처럼 풀면 됨 
	1원 -> 1개, 2원 -> 2개 ... 10원 = dp[10-10]+1, 11원 = dp[10]+1개 ...
	*/
	
    for (int i = 1; i < 100; ++i)
        for (auto &j : segment)
            if(i >= j)
				dp[i] = min(dp[i], dp[i-j]+1);
	
	int t;
    cin >> t;

    while (t--){
		LL n;
		cin >> n;

		LL result = 0;
		while (n)
			result += dp[n%100]
			, n /= 100;

		cout << result << '\n';
    }
}