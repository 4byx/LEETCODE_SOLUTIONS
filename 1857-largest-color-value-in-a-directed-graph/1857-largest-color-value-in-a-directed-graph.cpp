class Solution {
public:
    int ans = 0;
    int dp[100001][26];
    
    bool cyclecheck(int curr,int vis[], vector<int> gr[]){
        vis[curr]=2;
        for(auto x : gr[curr]){
            if(vis[x] == 0){
                bool subans = cyclecheck(x,vis,gr);
                if(subans) return true;
            }else if(vis[x]==2) return true;
        }
        vis[curr] = 1;
        return false;
    }
    
    void dfs(int curr , int vis[] , vector<int> gr[] , string &colors){
        
        vis[curr]=1;
        
        for(auto x : gr[curr]){
            if(!vis[x]){
                dfs(x,vis,gr,colors);
            }
                for(int i = 0 ; i < 26 ; i++){
                    dp[curr][i] = max(dp[x][i],dp[curr][i]);
                    ans = max({dp[curr][i],ans});
                }
        }
        
        dp[curr][colors[curr]-'a']++;
        for(int j = 0 ; j < 26 ; j++){
            ans = max({dp[curr][j],ans});
        }
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> gr[n]; memset(dp,0,sizeof(dp));
        
        for(auto x : edges){
            gr[x[0]].push_back(x[1]);
        }
        
        int vis[n]; memset(vis,0,sizeof(vis));
        
        // cycle
        bool cycle = false;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i] and !ans) cycle |= cyclecheck(i,vis,gr);
        }
        if(cycle) return -1;
        
        memset(vis,0,sizeof(vis));
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){ 
                dfs(i,vis,gr,colors);
                
            }
        }
        
        return ans;
    }
};