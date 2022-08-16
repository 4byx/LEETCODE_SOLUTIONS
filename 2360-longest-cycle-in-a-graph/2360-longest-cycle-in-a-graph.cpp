class Solution {
public:
    int ans , found;
    void dfs(int curr , int par , vector<int> gr[] , int vis[], int dep[],int sta[]){
        vis[curr] = 1;
        sta[curr]=1;
        if(par == -1) dep[curr] = 0;
        else dep[curr] = dep[par]+1;
        
        for(auto x : gr[curr]){
            if(!vis[x]){
                dfs(x,curr,gr,vis,dep,sta);
            }else if(sta[x]==1){
                found = 1;
                ans = max({ans,dep[curr]-dep[x]+1});
            }
        }
        sta[curr]=0;
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> gr[n];
        int vis[n] , dep[n] , sta[n];
        memset(vis,0,sizeof(vis));
        memset(dep,0,sizeof(dep));
        memset(sta,0,sizeof(sta));
        
        for(int i = 0 ; i < n;  i++){
            if(edges[i] == -1) continue;
            gr[i].push_back(edges[i]);
        }
        for(int i = 0 ; i < n ; i++)
            if(!vis[i]) dfs(i,-1,gr,vis,dep,sta);
        if(!found) return -1;
        
        return ans;
        
    }
};