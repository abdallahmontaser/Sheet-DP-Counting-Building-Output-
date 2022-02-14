#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, K, X;
vl ve;
ll dp[201][201][201];
ll sol(int i, int prev, int rem)
{
	if (i > N)
		return 0;
	ll& ret = dp[i][prev][rem];
	if (~ret)
		return ret;
	ret = -1e12;
	if (i - prev < K)
		ret = sol(i + 1, prev, rem);
	if (rem)
		ret = max(ret, ve[i] + sol(i + 1, i, rem - 1));
	return ret;
}
void solve()
{
	cin >> N >> K >> X;;
	ve = vl(N + 1);
	clr(dp, -1);
	for (int i = 1; i <= N; i++)
		cin >> ve[i];
	cout << max(sol(1, 0, X), -1ll);
}
int main()
{
	solve();
}
