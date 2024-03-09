//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        // length we can achieve from any index after r iterations
        long long finalLength = (1 << r);
        int x = finalLength;
        int i = 0;
        while(n >= finalLength){
            finalLength += x;
            i++;
        }
        //cout << i << endl;
        string temp;
        temp.push_back(s[i]);
        while(r--){
            string t;
            for(auto i : temp){
                if(i == '0'){
                    t.push_back('0');
                    t.push_back('1');
                }else{
                    t.push_back('1');
                    t.push_back('0');
                }
            }
            temp = t;
        }
        //cout << endl;
        //cout << x << " " << finalLength << " " << endl;
        n = x - (finalLength - (n+1));
        //cout << n << endl;
        return temp[n-1];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends