//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<pair<int,int>>> v (n ,vector<pair<int,int>>(n));
        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < n ;  j++){
                v[i][j].first = (a[i][j] == 'X' ? ((i == 0) ? 1 : v[i-1][j].first + 1) : 0);
                v[i][j].second = (a[i][j] == 'X' ? ((j == 0) ? 1 : v[i][j-1].second + 1) : 0);
            }
        }
        int ans= 0;
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                int s = min(v[i][j].first , v[i][j].second);
                while(s > ans){
                    if(v[i-s+1][j].second >= s && v[i][j-s+1].first >= s){
                        ans = s;
                        break;
                    }else{
                        s--;
                    }
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends