#include<bits/stdc++.h>
using namespace std;
string S;
pair<int, string> dp[(int)1e3][(int)1e3];
pair<int, string> Best(pair<int, string>A, pair<int, string>B)
{
	if (A.first > B.first)
		return A;
	else if (A.first < B.first)
		return B;
	else if (A.second < B.second)
		return A;
	else
		return B;
}
pair<int, string> Build(int i, int j)
{
	if (i > j)
		return { 0, "" };
	if (i == j)
		return { 1,string(1,S[i]) };
	pair<int, string>& ret = dp[i][j];
	if (~ret.first)
		return ret;
	if (S[i] == S[j])
	{
		ret.first = 2 + Build(i + 1, j - 1).first;
		ret.second = S[i] + Build(i + 1, j - 1).second + S[j];
	}
	else
		ret = Best(Build(i + 1, j), Build(i, j - 1));
	return ret;
}
void memo()
{
	for (int i = 0; i < 1e3; i++)
		for (int j = 0; j < 1e3; j++)
			dp[i][j].first = -1;
}
void solve()
{
	while (cin >> S)
	{
		memo();
		cout << Build(0, S.size() - 1).second << "\n";
	}
}
int main()
{
	solve();
}
