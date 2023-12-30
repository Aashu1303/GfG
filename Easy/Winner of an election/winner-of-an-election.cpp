//{ Driver Code Starts
#include <iostream>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n){
        map<string,int> mp;
        for (int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        int maxm = INT_MIN;
        for(auto i : mp){
            maxm = max(i.second , maxm);
        }
        vector<string> res;
        for (auto it : mp){
            if (it.second == maxm){
                res.push_back(it.first);
                res.push_back(to_string(it.second));
                break;
            }
        }
    
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends