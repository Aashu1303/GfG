//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        set <int> s;
        bool prime[n+1];
        memset(prime , true , sizeof(prime));
        for(int i = 2 ; i*i <= n ; i++){
            if(prime[i]){
                for(int j = i*i ; j <= n ; j+=i){
                    prime[j] = false;
                }
            }
        }
        
        for(int i = 2 ; i <= n ; i++){
            if(prime[i] == true){
                s.insert(i);
                // cout << i << " ";
            }
        }
        
        for(auto x : s){
            int part = n - x;
            if(s.find(part) != s.end()){
                return {x,part};
            }
        }
        
        
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends