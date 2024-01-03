//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        int ans = 0;
        
        for(int i = 0 ; i < 32 ; i++){
            // to keep track that how many elements have set bit at that index
            int count = 0;
            for(int j = 0 ; j < N ; j++){
                if(arr[j] & (1<<i)) count++;
            }
            if(count % 3) ans += (1<<i);
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
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends