//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public: 
  
    void DFS(int u,vector<int> adj[],bool visited[],int &n,int &edge_s){
         
         visited[u]=true; 
         n++; 
        edge_s+=adj[u].size();
        
         for(int v:adj[u]){
            
            if(visited[v]==false){ 
              
              DFS(v,adj,visited,n,edge_s);  
            }  
         }
        
    } 
    
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
         
         bool visited[v+1]; 
         for(int i=0;i<v+1;i++){
             visited[i]=false;
         }
         
          vector<int> adj[v+1];
        for(int i=0; i<e; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        } 
        
        
        
         int count=0;
         for(int u=1;u<=v;u++){
              
              int n=0,edge_s=0;
              if(visited[u]==false){
                  DFS(u,adj,visited,n,edge_s); 
                  
                edge_s=edge_s/2; 
              if(edge_s==n*(n-1)/2){
                 count++; 
              }
              }   
            
             
         } 
         
         return count;
         
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends