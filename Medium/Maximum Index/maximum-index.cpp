//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) { 
        vector<pair<int  , int>> ar(n) ;
        for(int i = 0 ; i< n ; i++){
            ar[i] = {a[i],i} ;
        }
        sort(ar.begin() , ar.end()) ;
        int ans = 0 , i = ar[0].second ;
        for(int j = 0 ; j< n ; j++){
            i = min(ar[j].second , i) ;
            ans = max(ar[j].second - i , ans) ;
        }
        return ans ;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends