//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost){
        vector<int> ans(total+1);
        for(int i =  n - 1 ; i >= 0 ; i--){
            for(int j = total; j >= 0 ; j--){
                if(j >= cost[i]){
                    ans[j] = max(ans[j] ,1+ans[j - 0.1*cost[i]]);
                }
            }
        }
        
        return ans[total];
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends