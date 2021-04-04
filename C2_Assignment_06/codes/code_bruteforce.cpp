/*
Problem Statement:
Optimal Knapsack Filling Problem-Given two integer arrays val[0..n-1] and wt[0..n-1]
which represent values and weights associated with n items respectively. Also given an
integer which represents knapsack capacity, find out the maximum value subset of val[] 
such that sum of the weights of this subset is smaller than or equal to knapsack capacity.
*/

//ALGORITHM-1 (Brute Force)

#include<bits/stdc++.h>
using namespace std;


int n; //n is the number of items
int cap; //cap is the maximum capacity of knapsack

int solve_knapsack(vector<int>&val,vector<int>&wt,int Total_weight,int n)

{
		    //This is the base case i.e., if n is 0 then there are no items that can be used
			//or if Total_weight is 0 then the knapsack is of 0 capacity and no item can be put in it
			//and so maximum sum of values possible in either case will be 0.
			if(Total_weight==0||n==0)
				return 0;
				
			//If the weight of the current item is greater than the current knapsack capacity,
			//then we cannot add its value into the knapsack and so we leave it.
			else if(wt[n-1]>Total_weight)
				return solve_knapsack(val,wt,Total_weight,n-1);	
			
			
			//Now, we have a choice: 
			//-> add the current item into the knapsack 
			//-> leave the current item, 
			//so we take the maximum of the 2 cases 
			else
				return max(solve_knapsack(val,wt,Total_weight,n-1),solve_knapsack(val,wt,Total_weight-wt[n-1],n-1)+val[n-1]);
	
}

/*This function will initialize variables n , cap and elements of
arrays val , wt with random values in the range 1-1000 .*/
void getRandomValues(vector<int>&val,vector<int>&wt)
{
	srand(time(0));// srand() with time(0) as the seeding value will make sure that the rand() function
	// returns a new random value every time code is run.

	n=50+rand()%50; //Here n will be assigned a random value in the range 50-1000 
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

	//Uncomment the following lines(45-49) to give manual input.*/

	/*cin>>n>>cap;
	val.assign(n,0);
	 wt.assign(n,0);
	for(int i=0;i<n;i++)
		cin>>val[i]>>wt[i];*/

	cout<<"Number of items (n) is :\n"<<n<<endl;
	cout<<"\nMaximum capacity of knapsack is :\n"<<cap<<endl;
	cout<<"\nThe values and weights of the items: \n";
	cout<<"Value Weight"<<endl;
	for(int i=0;i<n;i++)
		cout<<val[i]<<"   "<<wt[i]<<endl;

	cout<<"\nMaximum Value that can be attained is:\n";
    clock_t start, end;//measuring time
    start = clock();
	cout<<solve_knapsack(val,wt,cap,n)<<endl;
    end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
 cout << "Time taken by program is : " <<  time_taken << setprecision(10);
	

}
