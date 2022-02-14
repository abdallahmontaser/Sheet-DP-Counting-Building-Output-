#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, dp[(int)1e3][(int)1e3];
string S;
int sol(int i, int j)
{
	if (i > j)
		return 0;
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	ret = INT_MAX;
	if (S[i] == S[j])
		ret = sol(i + 1, j - 1);
	ret = min(ret, 1 + sol(i + 1, j));
	ret = min(ret, 1 + sol(i, j - 1));
	return ret;
}
string Build(int i, int j)
{
	if (i > j)
		return "";
	if (i == j)
		return string(1, S[i]);
	int ret = dp[i][j];
	if (S[i] == S[j] && ret == sol(i + 1, j - 1))
		return string(1, S[i]) + Build(i + 1, j - 1) + string(1, S[j]);
	else if (ret == 1 + sol(i + 1, j))
		return string(1, S[i]) + Build(i + 1, j) + string(1, S[i]);
	else if (ret == 1 + sol(i, j - 1))
		return string(1, S[j]) + Build(i, j - 1) + string(1, S[j]);
}
void solve()
{
	while (cin >> S)
	{
		N = S.size();
		clr(dp, -1);
		cout << sol(0, N - 1) << " ";
		cout << Build(0, N - 1) << "\n";
	}
}
int main()
{
	solve();
}
