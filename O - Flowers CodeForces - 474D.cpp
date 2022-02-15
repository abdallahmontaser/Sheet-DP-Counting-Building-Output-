#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int const Mod = 1e9 + 7;
int T, K, A, B, dp[(int)1e5 + 4];
int sol(int cnt)
{
	if (cnt == 0)
		return 1;
	if (cnt < 0)
		return 0;
	int& ret = dp[cnt];
	if (~ret)
		return ret;
	ret = ((sol(cnt - 1) % Mod) + (sol(cnt - K) % Mod)) % Mod;
	return ret % Mod;
}
void solve()
{
	cin >> T >> K;
	clr(dp, -1);
	sol(1e5);
	dp[0] = 0;
	for (int i = 1; i <= 1e5; i++)
		dp[i] = ((dp[i] % Mod) + (dp[i - 1] % Mod)) % Mod;
	while (T--)
	{
		cin >> A >> B;
		cout << ((dp[B] - dp[A - 1]) + Mod) % Mod << "\n";
	}
}
int main()
{
	solve();
}
