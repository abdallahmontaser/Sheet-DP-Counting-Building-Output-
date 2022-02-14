#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, T, W, dp[30][(int)1e3 + 1];
vector<pair<int, int>>ve, answer;
int sol(int i, int rem)
{
	if (i == N)
		return 0;
	int& ret = dp[i][rem];
	if (~ret)
		return ret;
	ret = sol(i + 1, rem);
	if ((ve[i].first * (3 * W)) <= rem)
		ret = max(ret, ve[i].second + sol(i + 1, rem - (ve[i].first * (3 * W))));
	return ret;
}
void Build(int i, int rem)
{
	if (i == N)
		return;
	int ret = dp[i][rem];
	if (((ve[i].first * (3 * W)) <= rem) && ret == ve[i].second + sol(i + 1, rem - (ve[i].first * (3 * W))))
	{
		answer.push_back(ve[i]);
		Build(i + 1, rem - (ve[i].first * (3 * W)));
	}
	else
		Build(i + 1, rem);
}
void solve()
{
	while (cin >> T >> W)
	{
		if (answer.size())
			cout << "\n";
		cin >> N;
		ve = vector<pair<int, int>>(N);
		answer.clear();
		clr(dp, -1);
		for (auto& it : ve)cin >> it.first >> it.second;
		cout << sol(0, T) << "\n";
		Build(0, T);
		cout << answer.size() << "\n";
		for (auto& it : answer)
			cout << it.first << " " << it.second << "\n";
	}
}
int main()
{
	solve();
}
