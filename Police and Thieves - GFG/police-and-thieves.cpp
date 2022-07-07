// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution {
public:
	int catchThieves(char arr[], int n, int k)
	{
		vector<int> th;
		vector<int> pl;

		for (int i = 0 ; i < n ; i++) {
			if (arr[i] == 'P') pl.push_back(i);
			else th.push_back(i);
		}
		int i = 0 , j = 0 , cnt = 0;
		int l = pl.size() , m = th.size();

		while (i < l and j < m) {
			if (abs(pl[i] - th[j]) <= k) {
				cnt++; i++; j++;
			} else if (pl[i] - th[j] > k) {
				j++;
			} else if (th[j] - pl[i] > k) {
				i++;
			}
		}

		return cnt;
		// Code here
	}
};
// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends