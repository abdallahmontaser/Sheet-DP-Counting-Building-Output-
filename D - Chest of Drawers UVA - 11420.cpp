#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, S;
ll dp[66][66][2];
ll sol(int i, int rem, int prev)
{
	if (i == N)
		return((rem == 0) ? 1 : 0);
	ll& ret = dp[i][rem][prev];
	if (~ret)
		return ret;
	ret = sol(i + 1, rem, 1) + sol(i + 1, rem - (!prev), 0);
	return ret;
}
void solve()
{
	while (cin >> N >> S)
	{
		if (N < 0 && S < 0)
			break;
		clr(dp, -1);
		cout << sol(0, S, 0) << "\n";
	}
}
int main()
{
	solve();
}
