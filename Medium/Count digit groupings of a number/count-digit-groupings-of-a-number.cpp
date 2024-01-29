//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int dp[101][901];
    int solve(string &str , int index , int sum){
        if(index == str.length()) return 1;
        int currentSum = 0;
        int ans = 0;
        if(dp[index][sum] != -1) return dp[index][sum];
        for(int i = index ; i < str.length() ; i++){
            currentSum += str[i] - '0';
            if(currentSum >= sum){
                ans += solve(str , i+1 , currentSum);
            }
        }
        return dp[index][sum] = ans;
    }
    
    
	public:
	int TotalCount(string str){
	    memset(dp , -1, sizeof(dp));
	    return solve(str,0,0);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends