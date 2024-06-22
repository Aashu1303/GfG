//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        stringstream s(sentence);
        string i;
        vector<string> v;
        long long ans = -1;
        while(s >> i){
            if(i[0] >= '1' && i[0] <= '9'){
                bool flag = true;
                for(int j = 0 ; j < i.size() ; j++){
                    if(i[j] == '9') flag = false;
                }
                if(flag) ans = max(ans , stoll(i));
            } 
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends