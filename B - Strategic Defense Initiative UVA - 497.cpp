#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int T, N, dp[(int)1e3][(int)1e3+1];
string S;
vi ve;
int sol(int i, int prev)
{
    if (i == N)
        return 0;
    int& ret = dp[i][prev];
    if (~ret)
        return ret;
    ret = sol(i + 1, prev);
    if (ve[i] > ve[prev])
        ret = max(ret, 1 + sol(i + 1, i));
    return ret;
}
void Build(int i, int prev)
{
    if (i == N)
        return;
    int& ret = dp[i][prev];
    if (ve[i] > ve[prev] && ret == 1 + sol(i + 1, i))
    {
        cout << ve[i] << "\n";
        Build(i + 1, i);
    }
    else
        Build(i + 1, prev);
}
void solve()
{
    cin >> T;
    cin.ignore();
    cin.ignore();
    while (T--)
    {
        clr(dp, -1);
        ve.clear();
        while (getline(cin, S) && S != "")
            ve.push_back(stoi(S));
        N = ve.size();
        ve.push_back(INT_MIN);
        cout << "Max hits: " << sol(0, N) << "\n";
        Build(0, N);
        if (T)
            cout << "\n";
    }
}
int main()
{
    solve();
}
