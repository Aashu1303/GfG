//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n % 2 != 0) return false;
        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            int target = nums[i] % k;
            if(mp[abs(k - target)] > 0){
                count ++;
                mp[abs(k - target)]--;
            }else{
                if(target == 0) mp[k]++;
                else mp[target]++;
            }
        }
        
        if(count == n/2) return true;
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends