//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        long long ans = 0;
        
        if (y < x) {
            swap(x, y);
            swap(arr, brr);
        }
        
        for (auto it : brr) ans += it;
        
        priority_queue<long> pq; 
        priority_queue<long , vector<long> , greater<long>> minH; 
        int count = y;
        for (int i = 0; i < n; i++) {
            if (arr[i] > brr[i]) {
                pq.push((arr[i] - brr[i]));
            }else{
                minH.push(abs(arr[i] - brr[i]));
                y--;
            }
        }
        
        while (!pq.empty() && x) {
            ans += pq.top();
            // cout << pq.top() << endl;
            pq.pop();
            x--;
        }
        //cout << x << " " << y << endl;    
        while (!minH.empty() && (y<0)) {
            ans -= minH.top();
            minH.pop();
            y++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends