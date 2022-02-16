#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, W, st_x, st_y, en_x, en_y, x, y;
ll dp[31][31];
int can[31][31][31][31];
char ch;
map<pair<pair<int, int>, pair<int, int>>, int>save;
bool vaild(int i, int j)
{
	return (i >= 1 && j >= 1 && i <= N && j <= N);
}
ll sol(int i, int j)
{
	if (!vaild(i, j))
		return 0;
	if (i == en_x && j == en_y)
		return 1;
	ll& ret = dp[i][j];
	if (~ret)
		return ret;
	ret = 0;
	if (!can[i][j][i + 1][j])
		ret += sol(i + 1, j);
	if (!can[i][j][i][j + 1])
		ret += sol(i, j + 1);
	return ret;
}
void solve()
{
	cin >> N >> st_x >> st_y >> en_x >> en_y >> W;
	clr(dp, -1);
	clr(can, 0);
	while (W--)
	{
		cin >> x >> y >> ch;
		if (ch == 'N')
			can[x][y][x][y + 1] = can[x][y + 1][x][y] = 1;
		else if (ch == 'W')
			can[x][y][x - 1][y] = can[x - 1][y][x][y] = 1;
		else if (ch == 'S')
			can[x][y][x][y - 1] = can[x][y - 1][x][y] = 1;
		else if (ch == 'E')
			can[x][y][x + 1][y] = can[x + 1][y][x][y] = 1;
	}
	cout << sol(st_x, st_y) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
