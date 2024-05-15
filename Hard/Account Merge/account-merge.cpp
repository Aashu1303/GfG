//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int find(int a, int par[])
    {
        if(a == par[a])
            return a;
        return par[a] = find(par[a], par);
    }
     
    void unionn(int a,int b,int par[],int sz[], set<string> s[]){
    	a = find(a,par);
    	b = find(b,par);
    	if(a == b)
    		return ;
    	if(sz[a]>sz[b])
    		swap(a,b);
    	par[a] = b;
    	sz[b] += sz[a];
    	s[b].insert(s[a].begin(), s[a].end());
    }
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        int par[n], sz[n];
        set<string> s[n];
        for(int i=0;i<n;i++)
            par[i] = i, sz[i] = 1, s[i].insert(accounts[i].begin() + 1, accounts[i].end());
        
        for(int i=0;i<accounts.size();i++)
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;
                unionn(mp[accounts[i][j]], i, par, sz, s);
                mp[accounts[i][j]] = i;
            }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
            if(par[i] == i)
            {
                // vector<int> ansHere(s[i].begin(), s[i].end());
                ans.push_back({accounts[i][0]});
                ans.back().insert(ans.back().end(), s[i].begin(), s[i].end());
                // ans.back().push_back(ansHere);
            }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends