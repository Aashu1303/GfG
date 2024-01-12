//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string removeKdigits(string S, int k)
    {
        int n = S.length();
        stack<char> s;
        for (int i = 0; i < n; i++){
            while ((!s.empty()) && (S[i] < s.top()) && k > 0){
                s.pop();
                k--;
            }

            if ((S[i] != '0' && s.empty()) || !s.empty()){
                s.push(S[i]);
            }
        }

        while (k > 0 && (!s.empty())){
            s.pop();
            k--;
        }

        string ans = "";
        
        while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends