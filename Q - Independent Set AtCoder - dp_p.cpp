#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int const Mod = 1e9 + 7;
int N, u, v;
ll dp[(int)1e5][2];
vector<vi>adj;
ll sol(int node, int  perv_node, int prev_color)
{
	ll& ret = dp[node][prev_color];
	if (~ret)
		return ret;
	ret = 1;
	for (auto& child : adj[node])
	{
		if (child != perv_node)
		{
			if (!prev_color)  // black
				ret = (ret * sol(child, node, 1)) % Mod;
			else      // white
				ret = (ret * (sol(child, node, 1) + sol(child, node, 0))) % Mod;
		}
	}
	return ret % Mod;
}
void solve()
{
	cin >> N;
	adj = vector<vi>(N);
	clr(dp, -1);
	for (int i = 0; i < N - 1; i++)
		cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
	cout << ((sol(0, -1, 0) % Mod) + (sol(0, -1, 1) % Mod)) % Mod;
}
int main()
{
	solve();
}
