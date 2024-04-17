//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <ext/pb_ds/assoc_container.hpp> // Including necessary headers
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; // Using the namespace for pb_ds

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> st; // Defining a data structure pbds using GNU pb_ds
class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here
        st s;
        int ans = 0;
        
        for(int i = n-1 ; i >= 0 ; i--){
            int val = arr[i]*i; 
            ans += s.order_of_key(val);
            s.insert(val);
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends