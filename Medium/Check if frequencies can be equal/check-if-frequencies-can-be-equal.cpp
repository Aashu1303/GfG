//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // if there are only two distinct frequecies then only we can make them similar 
	    // by removing one element
	    unordered_map<int,int> mp,mp1;
	    set<int> set;
	    vector<int> v;
	    for(auto i : s){
	        mp[i-'a']++;
	    }
	    for(auto i : mp){
	        if(i.second != 0){
	            set.insert(i.second);
	        }
	    }
	    
	    // if there are more than 2 distinct frequencies
	    if(set.size() > 2){
	        return false;
	    }
	    
	    // if there is only one distinct frequencies
	    if(set.size() == 1){
	        return true;
	    }
	    
	    for(const auto& element : set){
	        v.push_back(element);
	    }
	    
	    // now when we have only two different frequencies, we need to check number of elements 
	    // having that frequency 
	    
	    int count = 0 , count1 = 0;
	    for(auto i : mp){
	        if(i.second == v[0]){
	            count++;
	        }else{
	            count1++;
	        }
	    }
	    //cout << v[0] << " " << v[1] << endl;
	    // so now we need to check which element has only that particular frequency
	    // if number of elements for both frequencies are greater than 1 then its not possible to 
	    // remove a single element and get same frequency
	    
	    if(count > 1 && count1 > 1){
	        return false;
	    }else{
	        if(count1 == 1 || (count == 1 && count1 == 1)){
	            if(v[0] == 1){
	                return true;
	            }
	            if(v[1] - v[0] != 1) return false;
	        }else{
	            if(v[0] != 1){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}   
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends