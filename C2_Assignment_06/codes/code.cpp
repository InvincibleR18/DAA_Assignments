/*
Problem Statement:
Optimal Knapsack Filling Problem-Given two integer arrays val[0..n-1] and wt[0..n-1]
which represent values and weights associated with n items respectively. Also given an
integer which represents knapsack capacity, find out the maximum value subset of val[] 
such that sum of the weights of this subset is smaller than or equal to knapsack capacity.
*/

#include<bits/stdc++.h>
using namespace std;

int n; //n is the number of items
int cap; //cap is the maximum capacity of knapsack

/*solve_knapsack() returns the maximum sum of values that
can be obtained from the given items in the given knapsack capacity.*/
int solve_knapsack(vector<int>&val,vector<int>&wt)
{
	//dp is a 2D vector with dimensions (n+1)*(cap+1)
	/*dp[i][j] will store the maximum sum of values that can be obtained 
	by using the first i items and a knapsack capacity of j */
	vector<vector<int>>dp(n+1,vector<int>(cap+1));

	//Now we iterate over all cells of dp and fill them using Dynamic Programming.
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=cap;j++)
		{
			//This is the base case i.e., if i is 0 then there are no items that can be used
			//or if j is 0 then the knapsack is of 0 capacity and no item can be put in it
			//and so maximum sum of values possible in either case will be 0.
			if(i==0||j==0)
				dp[i][j]=0;

			//If the weight of the current item is greater than the current knapsack capacity,
			//then we cannot add its value into the knapsack and so we leave it.
			else if(wt[i-1]>j)
				dp[i][j]=dp[i-1][j];

			//Now, we have a choice: 
			//-> add the current item into the knapsack i.e., dp[i][j]=dp[i-1][j-wt[i-1]]+val[i-1]
			//-> leave the current item, i.e., dp[i][j]=dp[i-1][j]
			//so we take the maximum of the 2 cases and assign it to dp[i][j].
			else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
		}
	} 
	return dp[n][cap];
}

/*This function will initialize variables n , cap and elements of
arrays val , wt with random values in the range 1-1000 .*/
void getRandomValues(vector<int>&val,vector<int>&wt)
{
	srand(time(0));// srand() with time(0) as the seeding value will make sure that the rand() function
	// returns a new random value every time code is run.

	n=50+rand()%951; //Here n will be assigned a random value in the range 50-1000 
	cap=1+rand()%1000; //Here cap will be assigned a random value in the range 1-1000 

	//assign(n,0) will resize the vector to size n
	val.assign(n,0);
	wt.assign(n,0);

	for(int i=0;i<n;i++)
	{
		//Here vectors val and wt will be filled with random values in the range 1-1000 
		val[i]=1+rand()%1000;
		wt[i]=1+rand()%1000;
	}
}
int main()
{   
	vector<int>val; //val[i] stores the value of the i-th item.
	vector<int>wt; //wt[i] stores the weight of the i-th item.

	getRandomValues(val,wt);

	/*Uncomment the following lines(45-49) to give manual input.*/

	// cin>>n>>cap;
	// val.assign(n,0);
	// wt.assign(n,0);
	// for(int i=0;i<n;i++)
	// 	cin>>val[i]>>wt[i];

	cout<<"Number of items (n) is :\n"<<n<<endl;
	cout<<"\nMaximum capacity of knapsack is :\n"<<cap<<endl;
	cout<<"\nThe values and weights of the items: \n";
	cout<<"Value Weight"<<endl;
	for(int i=0;i<n;i++)
		cout<<val[i]<<"   "<<wt[i]<<endl;

	cout<<"\nMaximum Value that can be attained is:\n";
	cout<<solve_knapsack(val,wt)<<endl;
}