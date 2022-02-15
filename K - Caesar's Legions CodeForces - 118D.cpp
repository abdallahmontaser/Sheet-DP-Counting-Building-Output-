#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int const Mod = 100000000;
int N1, N2, K1, K2, dp[101][101][11][11];
int sol(int i, int j, int cnt1, int cnt2)
{
	if (i == N1 && j == N2)
		return 1;
	int& ret = dp[i][j][cnt1][cnt2];
	if (~ret)
		return ret;
	ret = 0;
	if (i < N1 && cnt1 < K1)
		ret += sol(i + 1, j, cnt1 + 1, 0), ret %= Mod;
	if (j < N2 && cnt2 < K2)
		ret += sol(i, j + 1, 0, cnt2 + 1) % Mod, ret %= Mod;
	return ret % Mod;
}
void solve()
{
	cin >> N1 >> N2 >> K1 >> K2;
	clr(dp, -1);
	cout << sol(0, 0, 0, 0) % Mod;
}
int main()
{
	solve();
}
