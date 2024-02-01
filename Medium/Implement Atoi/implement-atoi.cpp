//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        
        if(!(s[0] == '-' || (s[0] >= '0' && s[0] <= '9'))) return -1;
        bool negative = false;
        if(s[0] == '-'){
            negative = true;
        }
        int i = 0 , p = s.length()-1;
        if(negative){
            i++;
            p--;
        }
        long long ans = 0;
        while(s[i] == '0'){
            i++;
            p--;
        } 
        for(i;i < s.length() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                ans += (s[i]-'0') * pow(10,p);
                p--;
            }else{
                return -1;
            }
        }
        if(negative) ans = -ans;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends