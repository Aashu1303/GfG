//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &d) {
        //code here
        int len = s.length();
        bool dp[len+1] = {0};
        dp[0] = true;
        
        unordered_map<string,int> mp;
        for(auto &i : d) mp[i]++;
        
        for(int i = 0 ; i < len ; i++){
            if(!dp[i]){
                continue;
            }
            string temp;
            for(int j = i ; j < len ; j++){
                temp += s[j];
                // cout << temp << " ";
                if(mp[temp] != 0){
                    dp[j+1] = true;
                }
            }
            // cout << endl;
        }
        
        return dp[len]?1:0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends