//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int solve(int i , int j , int a[] , int b[] , int gap, vector<vector<int>>& dp){
	    if(i < 0 || j < 0) return 0;
	    if(dp[i][j] != -1) return dp[i][j];
	    int take = a[i] * b[j] + solve(i-1 , j-1 , a , b , gap,dp); 
	    int skip = INT_MIN;
	    if(gap > 0) skip = solve(i-1 , j , a , b , gap-1,dp);
	    
	    return dp[i][j] = max(take , skip);
	}
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
 		vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
		return solve(n-1,m-1,a,b,n-m , dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends