//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long ans = 0;
        long long sum = 0;
        for(long long i = 0 ;i < n ; i++){
            sum += (long)a[i];
            ans += (long)a[i] * i;
        }
        
        long long curr = ans;
        for(long long i = 1 ; i < n ; i++){
            curr += (sum - (long) n*a[n-i]);
            ans = max(ans , curr);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends