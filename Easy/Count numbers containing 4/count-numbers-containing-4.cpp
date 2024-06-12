//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool count(int n){
        while(n > 0){
            if(n%10 == 4) return 1;
            n = n/10;
        }
        return 0;
    }
  public:
    int countNumberswith4(int n) {
        // code here
        int ans= 0;
        for(int i = 3 ; i <= n ; i++){
            ans += (count(i));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends