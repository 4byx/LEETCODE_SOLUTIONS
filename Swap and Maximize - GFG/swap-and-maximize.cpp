// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    vector<int> a(n);
    sort(arr,arr+n);
    int i = 0 , j = n-1;
    
    int k = 0;
    while(i<=j){
        
        
        a[k++] = arr[i++];
        if(i>=j and k==n) break;
        a[k++] = arr[j--];
        
    }
    
    // for(auto x : a){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    
    long long int sum = 0;
    for(int i = 0 ; i < n ; i++){
        int ans = (abs(a[i%n]-a[(i+1)%n]));
        sum += ans;
    }
    return sum;
}