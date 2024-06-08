//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int s1 = 0 , s2 = 0;
        for(int i = 0 ; i < n ; i++){
            s1 += arr1[i];
        }
        for(int i = 0 ; i < n-1 ; i++){
            s2 += arr2[i];
        }
        
        int target = s1-s2;
        for(int i = 0 ; i < n ; i++){
            if(arr1[i] == target) return i;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends