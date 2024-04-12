//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        vector<long long> v(32,0);
        long long ans = 0;
        for(int j = 0 ; j < n ; j++){
            for(int i = 31 ; i >= 0 ; i--){
                if((1 << i) & arr[j]){
                    long long x = 1 << i;
                    ans += (x * v[i]);
                    v[i]++;
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
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends