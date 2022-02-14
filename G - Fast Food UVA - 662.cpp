#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, K, test = 1;
ll dp[201][201][31];
vi ve;
ll sol(int i, int prev, int rem)
{
	if (i > N)
		return ((rem == 0 && prev == N) ? 0 : INT_MAX);
	ll& ret = dp[i][prev][rem];
	if (~ret)
		return ret;
	int sum = 0;
	ret = sol(i + 1, prev, rem);
	for (int j = prev + 1; j <= N && rem; j++)
	{
		sum += abs(ve[j] - ve[i]);
		if (j >= i)
			ret = min(ret, sum + sol(j + 1, j, rem - 1));
	}
	return ret;
}
void Build(int i, int prev, int rem, int idx)
{
	if (i > N)
		return;
	ll ret = dp[i][prev][rem];
	int sum = 0;
	for (int j = prev + 1; j <= N && rem; j++)
	{
		sum += abs(ve[j] - ve[i]);
		if (j >= i && ret == sum + sol(j + 1, j, rem - 1))
		{
			cout << "Depot " << idx << " at restaurant " << i << " serves restaurants " << prev + 1 << " to " << j << "\n";
			Build(j + 1, j, rem - 1, idx + 1);
			return;
		}
	}
	Build(i + 1, prev, rem, idx);
}
void solve()
{
	while (cin >> N >> K)
	{
		if (!N && !K)
			break;
		ve = vi(N + 1);
		clr(dp, -1);
		for (int i = 1; i <= N; i++)
			cin >> ve[i];
		cout << "Chain " << test++ << "\n";
		sol(1, 0, K);
		Build(1, 0, K, 1);
		cout << "Total distance sum = " << sol(1, 0, K) << "\n\n";
	}
}
int main()
{
	solve();
}
