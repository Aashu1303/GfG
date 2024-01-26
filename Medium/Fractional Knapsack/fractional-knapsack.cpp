//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(struct Item& A, struct Item& B) {
        double val1 = (double) A.value / (double) A.weight;
        double val2 = (double) B.value / (double) B.weight;
        
        return val1 > val2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // sort according to val/wt
        sort(arr, arr+n, cmp);
        
        double ans = 0;
        
        for(int i=0; i<n; i++) {
            if(arr[i].weight <= W) {
                ans += arr[i].value;
                W -= arr[i].weight;
            } 
            else {
                double val = (double) arr[i].value / (double) arr[i].weight;
                ans += W * val;
                W = 0;
                break;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends