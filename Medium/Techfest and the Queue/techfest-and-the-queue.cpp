//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    //vector<int> ans(b+1);
	    //vector<int> sieve = sieveofErathosthenes(b);
	    int ans = 0;
	    for(int i = a ; i <= b ; i++){
	        int curr = i;
	        for(int p = 2 ; p <= sqrt(i) ; p++){
	            int power = 0;
	            while(curr % p == 0){
	                power++;
	                curr = curr/p;
	            }
	            ans += power;
	        }
	        if(curr > 1) ans++;
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends