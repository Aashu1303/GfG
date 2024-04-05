//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> v;
        int maxDeadline = 0;
        for(int i = 0 ; i < n ; i++){
            Job j = arr[i];
            maxDeadline = max(maxDeadline , j.dead);
            v.push_back({j.profit , j.dead});
        }
        
        vector<int> ans;
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int totalJobs = 0 , maxProfit = 0;
        set<int> s;
        for(int i = 1 ; i <= maxDeadline ; i++) s.insert(i);
        for(int i = 0 ; i < n ; i++){
            int curr = v[i].second;
            auto it = s.lower_bound(curr);
            if(it != s.end()){
                if(*it > curr){
                    if(it == s.begin()) continue;
                    it--;
                }
                s.erase(it);
                maxProfit += v[i].first;
                totalJobs++;
            }else if(!s.empty()){
                auto itt = *s.rbegin();
                s.erase(itt);
                maxProfit += v[i].first;
                totalJobs++;
            }
        }
        
        return {totalJobs,maxProfit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends