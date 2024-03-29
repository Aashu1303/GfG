//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> v;
    	for(int i =0 ; i < n ;i++) v.push_back({arr[i],dep[i]});
    	sort(v.begin(),v.end());
    	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>q;
    	int ans = 0;
    	for(int i = 0 ; i < n ; i++){
    	    int start = v[i].first , end = v[i].second; 
    	    while(!q.empty() && q.top().first < start){
    	        q.pop();
    	    }
    	    q.push({end,start});
    	    int size = q.size();
    	    ans = max(ans ,size);
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
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends