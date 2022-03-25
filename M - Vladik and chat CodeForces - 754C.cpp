#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, M, dp[100][101];
vector<string>Names, Messages, User;
map<string, int>index;
vector<vi>save;
vi answer;
string get_user(string S)
{
	return  S.substr(0, S.find(':'));
}
int found(string S, string T)
{
	int pos = 0;
	while ((pos = S.find(T, pos)) != std::string::npos)
	{
		int before = pos - 1;
		pos += T.size();
		if (!isdigit(S[before]) && !isalpha(S[before]))
		{
			if (pos == S.size())
				return 0;
			else if (!isdigit(S[pos]) && !isalpha(S[pos]))
					return 0;
		}
	}
	return 1;
}
void pre()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			string tem = get_user(Messages[j]);
			if (tem == "?")
				save[i][j] = found(Messages[j], Names[i]);
			else
				save[i][j] = (index[tem] == i);
		}
	}
}
int sol(int i, int prev)
{
	if (i == M)
		return 1;
	int& ret = dp[i][prev];
	if (~ret)
		return ret;
	ret = 0;
	if (User[i] == "?")
	{
		for (int j = 0; j < N; j++)
		{
			if (j != prev && save[j][i])
				ret |= sol(i + 1, j);
		}
	}
	else
	{
		if (index[User[i]] != prev && save[index[User[i]]][i])
			ret |= sol(i + 1, index[User[i]]);
	}
	return ret;
}
void Build(int i, int prev)
{
	if (i == M)
		return;
	int& ret = dp[i][prev];
	if (User[i] == "?")
	{
		for (int j = 0; j < N; j++)
		{
			if (j != prev && save[j][i] && ret == sol(i + 1, j))
			{
				answer[i] = j;
				Build(i + 1, j);
				break;
			}
		}
	}
	else
	{
		answer[i] = index[User[i]];
		Build(i + 1, index[User[i]]);
	}
}
void solve()
{
	cin >> N;
	Names = vector<string>(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> Names[i];
		index[Names[i]] = i;
	}
	cin >> M;
	cin.ignore();
	Messages = User = vector<string>(M);
	answer = vector<int>(M);
	for (int i = 0; i < M; i++)
	{
		getline(cin, Messages[i]);
		User[i] = get_user(Messages[i]);
	}
	save = vector<vi>(N, vi(M, 1));
	pre();
	clr(dp, -1);
	if (!sol(0, N))
		cout << "Impossible\n";
	else
	{
		Build(0, N);
		for (int i = 0; i < M; i++)
		{
			if (User[i] == "?")
				cout << Names[answer[i]] << ":" << Messages[i].substr(2) << "\n";
			else
				cout << Messages[i] << "\n";
		}
	}
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
