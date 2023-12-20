//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        /**if arr[] = {1} then answer will be 1
        *if arr[] = {1,2,3} then ans = 1 ^ 3 only cause
        *{1} ^ {2} ^ {1^2} ^ {2^3} ^ {3} ^ {1^2^3}
        * {1} ^ (2 ^ 1 ^ 2 ^ 2 ^ 3 ^ 1 ^ 2 ^ 3) ^ {3}
        * {1} ^ (0) ^ {3}
        * {1} ^ {3}
        * **/
        // we can also think like that when n is even then there are even number times 
        // every element is present in all the subarrays which making the xor sum equal 
        // to 0 for every number but its doesnt happen in case when there are odd number
        // of elements
        if(N % 2 == 0) return 0;
        
        int ans = 0;
        for(int i = 0 ; i < N ; i+=2){
            // since the indexing starts from so every odd element position becomes even
            ans ^= A[i];
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
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends