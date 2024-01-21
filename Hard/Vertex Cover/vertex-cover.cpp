//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            // code here
            int ans=16,k=(1<<n);
            for(int i=1;i<k;i++){
                int m=edges.size();
                for(auto j:edges){
                    if(i&(1<<(j.first-1)) || i&(1<<(j.second-1))){
                        m--;
                    }
                    else break;
                }
                if(m==0){
                    ans=min(ans,__builtin_popcount(i));
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends