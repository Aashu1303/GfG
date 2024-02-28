//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        if(s.size() <= 2){
            int x = stoi(s);
            return (x % 8 == 0 ? 1 : -1);
        }
        int l = s.length()-3;
        int x = stoi(s.substr(l,3));
        // cout << x << endl;
        return (x % 8 == 0 ? 1 : -1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends