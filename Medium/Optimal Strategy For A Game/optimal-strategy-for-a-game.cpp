//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    long long solve(int n , int arr[] , int i , int j , int count , bool first, vector<vector<long long>> &dp){
        if(count == n) return 0;
        long long take = 0 , skip = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(first){
            take = arr[i] + solve(n,arr,i+1,j,count+1,false,dp);
            skip = arr[j] + solve(n , arr, i , j-1 , count+1 , false, dp);
        }else{
            take = solve(n,arr,i+1,j,count+1,true,dp);
            skip = solve(n , arr, i , j-1 , count+1 , true,dp);
        }
        
        //cout << take << " " << skip << " " << first << endl;
        // take = take i and skip means take j not taking i
        if(first) return dp[i][j] = max(take,skip);
        else return dp[i][j] = min(take,skip);
    }
    public:
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>> dp(n+1 , vector<long long>(n+1,-1));
        return solve(n,arr,0,n-1,0,true,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends