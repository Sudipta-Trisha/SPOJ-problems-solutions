
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : July 25, 2020 9:28 PM
 *    Problem Name  : The Knapsack Problem
 *    Problem Limit : 1000 ms , 1536 MB
 *    Problem Url   : https://www.spoj.com/problems/KNAPSACK/
**/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int capacity, int profit[], int weight[])
{
	int mat[n+1][capacity+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=capacity; j++){
			if(i==0 || j==0){
				mat[i][j] = 0;
			}
			else if(weight[i-1]<=j){
				mat[i][j] = max(profit[i-1] + mat[i-1][j-weight[i-1]], mat[i-1][j]);
			}
			else{
				mat[i][j] = mat[i-1][j];
			}
		}
	}
	return mat[n][capacity];

}

int main()
{
    ios_base:: sync_with_stdio(0);

	int capacity,n;
	//cout<<"Enter the number of objects and capacity: ";
	cin >> capacity >> n;

	int profit[n+1],weight[n+1];
	//cout<<"Enter Profit: ";
	for(int i=0; i<n; i++){
		cin>> weight[i] >> profit[i];
	}

	cout<<knapsack(n,capacity,profit,weight) << endl;
	return 0;
}
