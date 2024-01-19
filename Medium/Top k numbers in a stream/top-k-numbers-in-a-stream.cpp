//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class myComp
{
    public:
    
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const
    {
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        
        return a.second > b.second;
    }
};

class Solution {
  public:
    
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        unordered_map<int,int> mp;
        
        set<pair<int,int>, myComp> st;
        
        int cnt;
        int tmp;
        int num;
        vector<int> ds;
        vector<vector<int>> ans;
        for(int i = 0; i < N; i++)
        {
            ds.clear();
            cnt = ++mp[arr[i]];
            tmp = K;
            
            if(cnt>=2)
            {
                st.erase({arr[i],cnt-1});
            }
            
            st.insert({arr[i],cnt});
            
            
            for(auto it : st)
            {
                if(tmp == 0)
                {
                    break;
                }
                
                num = it.first;
                ds.push_back(num);
                tmp --;
            }
            ans.push_back(ds);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends