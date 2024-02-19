//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<int,int> freq;
        for(auto &i : s){
            freq[i-'a']++;
        }
        priority_queue<int> v;
        for(auto i : freq){
            v.push(i.second);
        }
        while(k--){
            int top = v.top();
            v.pop();
            top--;
            v.push(top);
        }        
        
        long long ans = 0;
        while(!v.empty()){
            long long i = v.top();
            ans += (i *i);
            v.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends