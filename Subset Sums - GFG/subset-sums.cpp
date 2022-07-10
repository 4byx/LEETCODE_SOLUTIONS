// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void helper(vector<int> &arr , int i , int n , vector<int>& ans, int sum){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        
        sum += arr[i];
        helper(arr,i+1,n,ans,sum);
        sum -= arr[i];
        
        helper(arr,i+1,n,ans,sum);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        helper(arr,0,N,ans,0);
        return ans;
        // Write Your Code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends