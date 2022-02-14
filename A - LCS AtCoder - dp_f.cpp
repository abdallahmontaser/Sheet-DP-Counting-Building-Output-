#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
string S, T;
int si, st, dp[(int)3e3][(int)3e3];
int sol(int i, int j)
{
	if (i == si || j == st)
		return 0;
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	if (S[i] == T[j])
		ret = 1 + sol(i + 1, j + 1);
	ret = max(ret, sol(i + 1, j));
	ret = max(ret, sol(i, j + 1));
	return ret;
}
void Build(int i, int j)
{
	if (i == si || j == st)
		return;
	int& ret = dp[i][j];
	if (S[i] == T[j] && ret == 1 + sol(i + 1, j + 1))
	{
		cout << S[i];
		Build(i + 1, j + 1);
	}
	else if (ret == sol(i + 1, j))
		Build(i + 1, j);
	else
		Build(i, j + 1);
}
void solve()
{
	cin >> S >> T;
	si = S.size();
	st = T.size();
	clr(dp, -1);
	sol(0, 0);
	Build(0, 0);
}
int main()
{
	solve();
}
