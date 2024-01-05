//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{   
	    int mod = 1e9+7;
	    int n = N+3;
	    int dp[n];
	    dp[0] = 0;
	    dp[1] = 1;
	    dp[2] = 1;
	    for(int i = 3 ; i < n ; i++){
	        dp[i] = (dp[i-1] + dp[i-2])%mod;
	    }
	    
	    int ans = ((long long)dp[n-1] * (long long)dp[n-1])%mod;
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends