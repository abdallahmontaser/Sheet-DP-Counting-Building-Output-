#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, H, dp[30][1000], ans;
vi F, D, T, timee;
int sol(int i, int rem)
{
	if (rem < 5)
		return 0;
	int& ret = dp[i][rem];
	if (~ret)
		return ret;
	ret = INT_MIN;
	if (i != N - 1 && T[i] <= rem)
		ret = sol(i + 1, rem - T[i]);
	int number_fish = F[i], sum = 0;
	for (int time = 5; time <= rem; time += 5)
	{
		sum += number_fish;
		if (i != N - 1 && (time + T[i]) <= rem)
			ret = max(ret, sum + sol(i + 1, rem - (time + T[i])));
		else
			ret = max(ret, sum + sol(i + 1, 0));
		number_fish = max(0, number_fish - D[i]);
	}
	return ret;
}
void Build(int i, int rem)
{
	if (rem < 5)
		return;
	int ret = dp[i][rem];
	int number_fish = F[i], sum = 0;
	map<int, int>save;
	for (int time = 5; time <= rem; time += 5)
	{
		sum += number_fish;
		save[time] = sum;
		number_fish = max(0, number_fish - D[i]);
	}
	for (int time = rem; time >= 5; time -= 5)
	{
		if ((i != N - 1) && ((time + T[i]) <= rem) && (ret == save[time] + sol(i + 1, rem - (time + T[i]))))
		{
			timee.push_back(time);
			Build(i + 1, rem - (time + T[i]));
			return;
		}
		else if (ret == sum + sol(i + 1, 0))
		{
			timee.push_back(time);
			Build(i + 1, 0);
			return;
		}
	}
	if ((i != N - 1) && (T[i] <= rem) && (ret == sol(i + 1, rem - T[i])))
	{
		timee.push_back(0);
		Build(i + 1, rem - T[i]);
	}
}
void solve()
{
	while (cin >> N)
	{
		if (!N)
			break;
		cin >> H;
		if (timee.size())
			cout << "\n";
		F = D = vi(N);
		T = vi(N - 1);
		timee.clear();
		clr(dp, -1);
		for (auto& it : F) cin >> it;
		for (auto& it : D) cin >> it;
		for (auto& it : T) cin >> it, it *= 5;
		ans = sol(0, H * 60);
		Build(0, H * 60);
		while (timee.size() != N)
			timee.push_back(0);
		for (int i = 0; i < N; i++)
		{
			if (i == N - 1)
				cout << timee[i] << "\n";
			else
				cout << timee[i] << ", ";
		}
		cout << "Number of fish expected: " << ans << "\n";
	}
}
int main()
{
	solve();
}
