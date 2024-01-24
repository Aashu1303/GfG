//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool isCyclic(unordered_map<int, vector<int>> &adjList, int i, vector<int> &visited, int parent){
        visited[i] = 1;
        
        for(auto pa:adjList[i]){
            if(visited[pa]==0){
                bool f = isCyclic(adjList, pa, visited, i);
                if(f)
                return 1;
            }
            else if(pa != parent)
            return 1;
        }
        return 0;
    }
  
    int isTree(int n, int m, vector<vector<int>> &adj) {
        
        unordered_map<int, vector<int>> adjList;
        
        for(int i=0 ;i<adj.size() ;i++){
            int u = adj[i][0];
            int v = adj[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    
        vector<int> visited(n, 0);
        bool f = isCyclic(adjList, 0, visited, -1);
        
        if(f)  return 0;
        
        for(int i=0 ;i<n ;i++){
            if(visited[i]==0)
            return 0;
        }
        
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends