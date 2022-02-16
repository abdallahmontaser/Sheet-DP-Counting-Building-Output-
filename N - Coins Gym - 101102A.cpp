#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
int const Mod = 1e9 + 7;
void solve()
{
	int N, M, K, W; cin >> N >> M >> K >> W;
	vi ve1(N);
	vi ve2(M);
	ll dp[2][15001], ans = 0;
	clr(dp, 0);
	dp[0][0] = 1;
	dp[1][0] = 1;
	for (auto& it : ve1) cin >> it;
	for (auto& it : ve2) cin >> it;
	sort(all(ve1));
	sort(all(ve2));

	for (int i = 0; i < N; i++)
	{
		for (int w = 15000; w >= 0; w--)
		{
			if (w - ve1[i] >= 0)
				dp[0][w] += dp[0][w - ve1[i]], dp[0][w] %= Mod;
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int w = 15000; w >= 0; w--)
		{
			if (w - ve2[i] >= 0)
				dp[1][w] += dp[1][w - ve2[i]], dp[1][w] %= Mod;
		}
	}
	for (int i = 0; i <= W; i++)
	{
		if (abs((2 * i) - W) <= K)
			ans += (dp[0][i] * dp[1][W - i]) % Mod, ans %= Mod;
	}
	cout << ans << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
