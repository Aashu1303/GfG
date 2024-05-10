//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     void helper(vector<int>& arr, int i, int target, vector<int>& temp, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        if(i == arr.size() || target < 0) 
            return;
        // pick
        temp.push_back(arr[i]);
        helper(arr, i+1, target - arr[i], temp, res);
        temp.pop_back();
        // not pick
        int j = upper_bound(arr.begin() + i, arr.end(), arr[i]) - arr.begin();
        helper(arr, j, target, temp, res);
    }

    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(arr, 0, k, temp, res);
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends