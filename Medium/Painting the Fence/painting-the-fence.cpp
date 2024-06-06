//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

int MOD = 1e9+7;

class Solution{
    public:
    
    long long int solveTab(long long n, long long k){
        if(n==1) return k;
        long long int p = k, np = ((k-1)*k) % MOD, pp, npp;
        
        for(long long int i=3; i<=n; i++){
            pp = np % MOD;
            npp = ((np+p)%MOD * (k-1)%MOD) % MOD;
            
            p = pp % MOD;
            np = npp % MOD;
        }
        
        return (p+np)%MOD;
    }
    
    long long countWays(int n, int k){
        if(k==1){
            if(n<=2)return 1;
            else return 0;
        }
        return solveTab(n%MOD, k%MOD);
    }
};



//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends