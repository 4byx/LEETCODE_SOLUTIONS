// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int helper(int A[] , int N , int mid){
        int sum = 0 , cnt = 0;
        for(int i = 0 ; i < N ; i++){
            sum += A[i];
            if(sum > mid){
                sum = A[i];
                cnt++;
            }else if(sum == mid){
                sum = 0;
                cnt++;
            }
        }
        if(sum > 0) cnt++;
        return cnt;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int ans = -1;
        
        int low = A[N-1];
        int high = 0;
        for(int i = 0 ; i < N;  i++){
            high += A[i];
        }
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            int check = helper(A,N,mid);
            
            if(check <= M){
                ans = mid;
                high = mid-1;
            }else if(check > M){
                low = mid+1;
            }
            
        }
        return ans;
        //code here
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends