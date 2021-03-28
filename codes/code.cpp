/*
Problem Statement:
Given a string S, count the number of non-empty sub strings that are 
palindromes. A sub string is any continuous sequence of characters in the 
string. A string is said to be palindrome, if the reverse of the string is same 
as itself. Two sub strings are different if they occur at different positions in 
S. Solve using Dynamic programming.
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001]; //Memorization table that will be used to apply Dynamic Programming.
//A cell in it would store:
//-> -1 if the corresponding substring is not yet processed.
//->  0 if the corresponding substring is not a palindrome.
//->  1 if the corresponding substring is a palindrome.


/*This function will create and return a string of length n made of random characters.*/
string generateRandomString(int n)
{
	string s="";

	srand(time(0));// srand() with time(0) as the seeding value will make sure that the rand() function
	// returns a new random value every time code is run.

	for(int i=0;i<n;i++)
	{
		char randomChar='a'+rand()%26; //Here, the rand()%26 will generate a random value in the 
		//range 0 to 25. We add to it the ASCII value of a so now we will get a random ASCII value of one of 
		//the lowercase alphabets. And then it will be implicitly type casted to the character itself.

		s.push_back(randomChar); //Now, we wanted a string of length n, so we generate a random character 
		//and push it into an intitially empty string and repeat this process n times.
	}
	return s;
}

bool isPal(string s,int i,int j)
{
	if (i>j)
		return 1;

	//If the cell is not -1, it means we have aldready processed this substring and hence,
	//we directly return dp[i][j];
	if (dp[i][j]!=-1)
		return dp[i][j];

	//Now, the current substring will be a palindrome if and only if following 2 conditions are met:
	// 1. Its first and last characters are same.
	// 2. The substring made by removing the first and last characters is also a palindrome.

	//This if will check the first condition.
	if (s[i]!=s[j])
		return dp[i][j]=0;

	//This will check the second condition.
	return dp[i][j]=isPal(s,i+1,j-1);
}

/*This function will return the count of non-empty palindromic substrings in the given string s.*/
int countSubstrings(string s)
{
	memset(dp,-1,sizeof(dp)); //This will intialize all the values of the memorization table
	//with -1 representing that the substring corresponding to this cell has not yet been processed.

	int n=s.length();
	int count=0;

	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			//Here, i represents the starting index of the current substring that we are processing
			//and j represents the last index of that substring. 
			//So, we are checking all possible substrings.

			//isPal() will return true if the current substring is a palindrome otherwise false.
			if(isPal(s,i,j)) 
				count++;
		}
	}
	return count;
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

