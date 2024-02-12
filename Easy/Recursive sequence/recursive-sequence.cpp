//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        int MOD = 1e9+7;
        long long ans = 1 , curr = 2;
        for(int i = 1 ; i < n ; i++){
            long long x = 1;
            for(long long j = 0 ; j < i+1 ; j++){
                x = (curr * x) % MOD;
                curr++;
            }
            ans = (ans + x) % MOD;
        }
        return (ans % MOD);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends