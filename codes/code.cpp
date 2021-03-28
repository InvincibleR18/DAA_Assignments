#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPal(string s,int i,int j)
{
	if (i>j)
		return 1;

	if (dp[i][j]!=-1)
		return dp[i][j];

	if (s[i]!=s[j])
		return dp[i][j]=0;

	return dp[i][j]=isPal(s,i+1,j-1);
}

int countSubstrings(string s)
{
	memset(dp,-1,sizeof(dp));
	int n=s.length();
	int count=0;
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			if(isPal(s,i,j))
				count++;
		}
	}
	return count;
}

string generateRandomString(int n)
{
	string s="";
	srand(time(0));
	for(int i=0;i<n;i++)
	{
		char randomChar='a'+rand()%26;
		s.push_back(randomChar);
	}
	return s;
}

int main()
{ 
	int n;
	cout<<"Enter length of the string:\n";
	cin>>n;	

	string s;
	s=generateRandomString(n);

	/*Uncomment the follwing line ( cin>>s ) to give a string as input. 
	Currently a random string of given length is being generated and used.*/

    // cin>>s;  

	cout<<"\nApplying the algorithm on the following string:\n"<<s<<endl;

	cout<<"\nCount of non-empty palindromic substrings is:\n";
	cout<<countSubstrings(s)<<endl;;
}

