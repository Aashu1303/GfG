//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n){
        if(m == n) return -1;
        int a = m ^ n;
        int right = 31 , left = 0;
        
        for(int i = 0 ; i < 32 ; i++){
            if((m&(1<<i)) != (n&(1<<i))) return i+1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends