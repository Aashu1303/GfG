//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int ans = INT_MAX;
        vector<int> v(3,0);
        int l = 0 , r = 0;
        while(r < s.length()){
            v[s[r] - '0']++;
            while(l < r && (v[s[l] - '0'] > 1)){
                v[s[l] - '0']--;
                l++;
            }
            if(v[0] && v[1] && v[2]) ans = min(ans , r-l+1);
            r++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends