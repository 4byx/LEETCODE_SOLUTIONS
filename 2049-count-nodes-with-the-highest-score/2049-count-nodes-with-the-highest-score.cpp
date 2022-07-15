class Solution {
public:
    #define ll long long
    int dfs(int curr  , int par  , int * child , vector<int> gr[],int n,ll * ans){
        child[curr] = 1;
        int left=-1,right=-1;
        for(auto x : gr[curr]){
            if(x!=par){
                if(left==-1) left = dfs(x,curr,child,gr,n,ans);
                else if(right==-1) right = dfs(x,curr,child,gr,n,ans);
            }
        }
        child[curr] += ((left!=-1)?left:0) + ((right!=-1)?right:0);
        // cout<<curr<<" "<<left<<" "<<right<<"\n";
        ans[curr] = 1ll*((left!=-1)?left:1)*((right!=-1)?right:1)*((n-1-((left!=-1)?left:0)-((right!=-1)?right:0))>0?(n-1-((left!=-1)?left:0)-((right!=-1)?right:0)):1);
        return child[curr];
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> gr[n];
        
        for(int i = 1 ; i < n ; i++){
            gr[i].push_back(parents[i]);
            gr[parents[i]].push_back(i);
        }
        int child[n];
        ll ans[n];
        memset(ans,0,sizeof(ans));
        memset(child,0,sizeof(child));
        child[0] = dfs(0,-1,child,gr,n,ans);
        ll maxi = INT_MIN;
        // cout<<"\n ans : "; 
        for(int i = 0 ; i < n; i++){
            if(ans[i]>maxi) maxi = ans[i];
        }
        // cout<<"\n";
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            if(ans[i]==maxi) res++;
        }
        
        return res;
    }
};