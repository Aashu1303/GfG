//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
    {
        if(n%k!=0) return false;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i+=k){
            string d=s.substr(i,k);
            mp[d]++;
        }
        if(mp.size()<2) return true;
        for(auto i:mp) if(i.second==1 and mp.size()==2) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends