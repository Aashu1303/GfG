//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        // Code here
        int i = 0 , j = 0;
        bool left = 0 , right = 1 , down = 0 , up = 0;
        bool flag = false;
        while(true){
            if(mat[i][j] == 1){
                mat[i][j] = 0;
                if(left == 1){
                    left = 0;
                    up = 1;
                    i--;
                }else if(right == 1){
                    right = 0;
                    down = 1;
                    i++;
                }else if(down == 1){
                    down = 0;
                    left = 1;
                    j--;
                }else if(up == 1){
                    up = 0;
                    right = 1;
                    j++;
                }
            }else{
                if(left == 1){
                    j--;
                }else if(right == 1){
                    j++;
                }else if(down == 1){
                    i++;
                }else if(up == 1){
                    i--;
                }
            }
            
            if(i < 0){
                i = 0;
                flag = true;
            }
            if(j < 0){
                j = 0;
                flag = true;
            }
            if(i >= n){
                i = n-1;
                flag = true;
            }
            if(j >= m){
                j = m-1;
                flag = true;
            }
            if(flag) break;
        }
        
        return {i , j}; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends