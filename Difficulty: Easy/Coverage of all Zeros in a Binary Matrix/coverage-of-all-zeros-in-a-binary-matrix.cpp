//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if (matrix[i][j]) continue;
                
                for (int k = 0; k < 4; ++k) {
                    int nr = i  +dr[k];
                    int nc = j + dc[k];
                    
                    if (nr >= 0 and nr < n and nc >= 0 and nc < m)
                        ans += matrix[nr][nc];
                }
            }
        }
        return ans;
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
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends