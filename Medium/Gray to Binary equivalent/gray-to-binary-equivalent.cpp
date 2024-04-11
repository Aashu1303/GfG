//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        int i = -1 , m =n ;
        while(m > 0){
            m /= 2;
            i++;
        }
        bool f;
        if(n & (1 << i)){
            f = true;
        }else{
            f = false;
        }
        //cout << i << f << endl;
        i--;
        for(i ; i >= 0 ; i--){
            int j = i+1;
            if(n & (1 << j)){
                n ^= (1 << i);
            }
        } 
        return n;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends