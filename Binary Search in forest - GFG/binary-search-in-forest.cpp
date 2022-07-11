// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int helper(int mid , int tree[] , int n){
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(tree[i] > mid) ans += tree[i]-mid;
        }
        return ans;
    }
    int find_height(int tree[], int n, int k)
    {
        int low = 0;
        int high = 0;
        for(int i = 0; i < n ; i++){
            high = max({high,tree[i]});
        }
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            int check = helper(mid,tree,n);
            if(check == k){
                ans = mid;
                low = mid+1;
            }else if(check > k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends