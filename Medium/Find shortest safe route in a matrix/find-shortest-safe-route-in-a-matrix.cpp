//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include <vector>
#include <climits>
using namespace std;

int r , c;
int dp[1001][1001];
bool visited[1001][1001];


class Solution
{
    bool check(int i, int j, vector<vector<int>> &mat)
    {
        if (i - 1 >= 0 && mat[i - 1][j] == 0) return false;
        if (i + 1 < mat.size() && mat[i + 1][j] == 0) return false;
        if (j + 1 < mat[0].size() && mat[i][j + 1] == 0) return false;
        if (j - 1 >= 0 && mat[i][j - 1] == 0) return false;

        return true;
    }

    int dfs(int i, int j, vector<vector<int>> &mat)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || visited[i][j] || mat[i][j] == 0) return 100000;
        if (dp[i][j] != -1) return dp[i][j];

        if (!check(i, j, mat)) return 100000;
        if (j == 0) return mat[i][0];

        visited[i][j] = true;

        int left = mat[i][j] + dfs(i, j - 1, mat);
        int down = mat[i][j] + dfs(i + 1, j, mat);
        int top = mat[i][j] + dfs(i - 1, j, mat);

        visited[i][j] = false;

        return dp[i][j] = min(min(left, top), down);
    }

public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        r = mat.size();
        c = mat[0].size();
        
        memset(dp,-1,sizeof dp);
        memset(visited,false,sizeof visited);

        int ans = 100000;
        for (int i = 0; i < r; i++) {
            ans = min(ans, dfs(i, c - 1, mat));
        }

        return ans == 100000 ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends