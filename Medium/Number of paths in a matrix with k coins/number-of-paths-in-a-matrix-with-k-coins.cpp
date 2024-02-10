//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

long long dp[101][101][101];
class Solution {
    long long manuvering(int i , int j , int k , vector<vector<int>> &arr){
        if(i<0 || j < 0 || k <0) return 0;
        if(i == 0 && j == 0){
            if(k == arr[i][j]) return 1;
            return 0;
        }
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        long long left = manuvering(i,j-1,k-arr[i][j],arr);
        long long right = manuvering(i-1,j,k-arr[i][j],arr);
        
        return dp[i][j][k] = (left + right);
    }
public:
    // manuvering algorithm
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        memset(dp,-1,sizeof dp);
        return manuvering(n-1,n-1,k,arr);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends