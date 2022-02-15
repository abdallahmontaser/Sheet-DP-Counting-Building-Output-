#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, dp[(int)1e5 + 2][3][3];
vi ve;
int sol(int i, int prev, int flib)
{
	if (i == N)
		return 0;
	int& ret = dp[i][prev][flib];
	if (~ret)
		return ret;
	ret = sol(i + 1, prev, flib);
	if (flib == 0)
	{
		if (ve[i] != prev)
			ret = max(ret, 1 + sol(i + 1, ve[i], 0));
		else
			ret = max(ret, 1 + sol(i + 1, !ve[i], 1));
	}
	else if (flib == 1)
	{
		if (ve[i] != prev)
			ret = max(ret, 1 + sol(i + 1, ve[i], 2));
		else
		{
			ret = max(ret, 1 + sol(i + 1, !ve[i], 1));
			ret = max(ret, sol(i + 1, prev, 2));
		}
	}
	else if (flib == 2)
		ret = max(ret, (ve[i] != prev) + sol(i + 1, ve[i], 2));
	return ret;
}
void solve()
{
	string S;
	cin >> N >> S;
	ve = vi(N);
	clr(dp, -1);
	for (int i = 0; i < N; i++)ve[i] = (S[i] - '0');
	cout << sol(0, 2, 0);
}
int main()
{
	solve();
}
