//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int binarySearch(int n , int k){
        int left = 0 , right = n;
        int mid;
        while(left <= right){
            mid = (left + right)/2;
            if(mid > k){
                right = mid -1;
            }else if (mid < k){
                left = mid+1;
            }else{
                return mid;
            }
        }
        return mid;
    }
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> v;
        for(int i = 0 ; i < n ; i++){
            v.push_back({price[i] , i+1});
        }
        int ans = 0;
        sort(v.begin(),v.end());
        for(auto i : v){
            int curr = binarySearch(i.first * i.second , k);
            int x = round(curr / i.first);
            ans += x;
            k -= (x)*i.first;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends