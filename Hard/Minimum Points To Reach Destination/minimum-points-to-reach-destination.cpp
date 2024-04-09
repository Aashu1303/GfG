//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	vector<vector<int>> dp;
    int solve(vector<vector<int>>& points,int i, int j, int m, int n){
       
        if(i==m-1 && j==n-1)
            return min(points[i][j],0);
            
        if(i>=m || j>=n)
            return -1e7;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = points[i][j]+max(solve(points,i+1,j,m,n),solve(points,i,j+1,m,n));
        return dp[i][j] = min(ans,0);
    }
     
    int minPoints(int m, int n, vector<vector<int>> points) 
    { 
        // Your code goes here
        dp.resize(m+1,vector<int>(n+1,-1));
        int ans = solve(points,0,0,m,n);
        return ans==0 ? 1 : abs(ans-1);
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends