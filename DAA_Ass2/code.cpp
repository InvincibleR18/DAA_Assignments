#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
bool isPal(string s, int i, int j)
{
	if (i > j)
		return 1;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s[i] != s[j])
		return dp[i][j] = 0;

	return dp[i][j] = isPal(s, i + 1, j - 1);
}

int countSubstrings(string s)
{
	memset(dp, -1, sizeof(dp));
	int n = s.length();
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i ; j < n; j++)
		{
			if (isPal(s, i, j))
				count++;
		}
	}
	return count;
}

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("C:/Users/user/Desktop/cc/input.txt","r",stdin);
	    freopen("C:/Users/user/Desktop/cc/output.txt","w",stdout);
	#endif  
	string s;
    cin >> s;

	cout << countSubstrings(s);
	return 0;
}