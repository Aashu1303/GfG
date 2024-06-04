//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        char carry = '1';
        string ans;
        int n = 0;
        while(s[n] == '0' && n < s.size()-1) n++;
        for(int i = s.size()-1 ; i>= n ; i--){
            if(carry == '1' && s[i] == '1'){
                ans.push_back('0');
            }else if(carry == '1' && s[i] == '0'){
                carry = '0';
                ans.push_back('1');
            }else{
                ans.push_back(s[i]);
            }
        }
        
        if(carry == '1') ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends