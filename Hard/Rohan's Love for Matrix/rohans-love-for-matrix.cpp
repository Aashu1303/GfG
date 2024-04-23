//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int mod = 1000000007;
        int prev = 0 , ans = 1;
        for(int i = 0 ; i < n-1 ; i++){
            int x = ans;
            ans = (prev + ans) % (mod);
            prev = x;
        }
        
        return ans % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends