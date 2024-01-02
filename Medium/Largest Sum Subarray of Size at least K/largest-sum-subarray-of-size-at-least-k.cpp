//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    #define ll long long int
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) {
        ll sum = 0;
        for(ll i =0 ; i < k ; i++){
            sum += a[i];
        }
        
        ll last = 0;
        ll j = 0;
        ll ans = LLONG_MIN;
        ans = max(ans , sum);
        for(ll i = k  ; i < n ;  i++){
            sum += a[i];
            last += a[j++];
            ans = max(ans , sum);
            if(last < 0){
                sum -= last;
                ans = max(ans , sum);
                last = 0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends