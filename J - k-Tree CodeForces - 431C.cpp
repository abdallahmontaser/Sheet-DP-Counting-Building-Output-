#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int const Mod = 1e9 + 7;
int N, K, D, dp[101][101][2];
int sol(int cur, int cnt, int flag)
{
	if (cnt > N)
		return 0;
	if (cnt == N)
		return flag;
	int& ret = dp[cur][cnt][flag];
	if (~ret)
		return ret;
	ret = 0;
	if (cur < K)
		ret += sol(cur + 1, cnt, flag) % Mod;
	ret %= Mod;
	ret += sol(1, cnt + cur, flag || (cur >= D)) % Mod;
	return ret % Mod;
}
void solve()
{
	cin >> N >> K >> D;
	clr(dp, -1);
	cout << sol(1, 0, 0) % Mod;
}
int main()
{
	solve();
}
