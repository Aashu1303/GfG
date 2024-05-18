//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int ans = INT_MIN;
        int n = a.size();
        int l = 0 , r = n-1;
        while(l <= r){
            int mid = l+ (r-l) / 2;
            if(a[mid - 1] > a[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
            ans = max(ans , a[r]);
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends