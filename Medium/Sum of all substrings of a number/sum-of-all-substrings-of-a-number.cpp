//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        int n = s.size();
        long long mod = 1e9+7,ans = 0;
        vector<long long> dp(n,0);
        dp[0] = s[0] - '0';
        ans = dp[0];
        for(long long i = 1 ; i < n ; i++){
            long long curr = s[i] - '0';
            dp[i] = ((dp[i-1] * 10) % mod + (curr * (i+1))%mod) % mod;
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends