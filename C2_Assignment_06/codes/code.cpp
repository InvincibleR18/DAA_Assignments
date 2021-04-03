#include<bits/stdc++.h>
using namespace std;
int solve_knapsack(int n,int cap,vector<int>&val,vector<int>&wt)
{
	vector<vector<int>>dp(n+1,vector<int>(cap+1));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=cap;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(wt[i-1]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
		}
	}
	return dp[n][cap];
}
int main()
{
	int n,cap;
	cin>>n>>cap;
	vector<int>val(n),wt(n);
	for(int i=0;i<n;i++)
		cin>>val[i];
	for(int i=0;i<n;i++)
		cin>>wt[i];	
	cout<<solve_knapsack(n,cap,val,wt)<<endl;
}