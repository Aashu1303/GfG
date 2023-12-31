//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
       int dp[370][2030];
    //vector<vector<int>>dp;
    bool solve(int coins[], int sum, int idx, int N)
    {
        if(sum != 0 && (sum%20 == 0 || sum%24 == 0 || sum == 2024))
        {
            //cout << sum <<" " << idx << endl;
            return dp[idx][sum]=true;
            //return true;
        }
        if(idx >= N)
        {
            //return false;
            return dp[idx][sum]=false;
        }
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        bool ans = false;
        ans = solve(coins,sum+coins[idx],idx+1,N) || solve(coins,sum,idx+1,N);
        return dp[idx][sum]= ans;
    }
    int isPossible(int N , int coins[]) 
    {
        memset(dp,-1,sizeof(dp));
        //dp.resize(N,vector<int>(2025,-1));
        return solve(coins,0,0,N);
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends