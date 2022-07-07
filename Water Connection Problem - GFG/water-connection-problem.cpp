// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<vector<int>> ans;
        map<int,pair<int,int>> m;
        map<int,int> visited;
        for(int i = 0 ; i < (int)a.size() ; i++){
            m[a[i]] = {b[i],d[i]};
        }
        vector<int> indegree(n+1,0);
        for(int i = 0 ; i < (int)b.size() ; i++){
            indegree[b[i]]++;
        }
        
        vector<int> tra;
        for(int i = 0 ; i < (int)a.size() ; i++){
            if(indegree[a[i]] == 0){
                tra.push_back(a[i]);
            }
        }
        sort(tra.begin(),tra.end());
        
        for(auto x : tra){
            int temp = x;
            int mini =m[x].second;
            while(m.count(temp)==1){
                mini = min(mini,m[temp].second);
                temp = m[temp].first;
            }
            ans.push_back({x,temp,mini});
        }
        return ans;
        // code here
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends