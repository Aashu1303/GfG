//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int bs(int s,int e,int k ,int arr[]){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]>k){
                e = mid-1;
            }else{
                s = mid+1;
            }
            
        }
        return (s<e)?s:e;
    }
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int val = bs(0,n-1,k,arr);


        if(arr[val]==k)return k;
        int l = k-arr[val];
        int r = k;
        if(val+1<n){
           r = arr[val+1]-k; 
        }
        if(l==r){
            return arr[val+1];
        }
        return (l<r)?arr[val]:arr[val+1];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends