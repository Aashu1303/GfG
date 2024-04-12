//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long y) {
        long long x = y;
        long long i = 31 , j = 0;
        while(i > j){
            int m = ((1LL << i) & x) ? 1 : 0;
            int n = ((1LL << j) & x) ? 1 : 0;
            if(m != n){
                if(m){
                    x ^= (1LL << i);
                    x ^= (1LL << j);
                }else{
                    x ^= (1LL << i);
                    x ^= (1LL << j);
                }    
            }
            i--;
            j++;
        }
        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends