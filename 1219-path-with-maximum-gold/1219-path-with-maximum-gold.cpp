int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
class Solution {
public:
    int maxi;
    void dfs(int i , int j , int m , int n , vector<vector<int>> &vis,vector<vector<int>> &grid,int ans){
        vis[i][j]=1;
        maxi = max(ans,maxi);
        // cout<<grid[i][j]<<" ";
        for(int k = 0 ; k < 4 ; k++){
            int xx = i+dx[k];
            int yy = j+dy[k];
            
            if(xx>=0 and xx<m and yy>=0 and yy<n and !vis[xx][yy] and grid[xx][yy]){
                dfs(xx,yy,m,n,vis,grid,ans+grid[xx][yy]);
                
            }
        }
        vis[i][j]=0;
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        maxi = 0;
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]!=0){
                    dfs(i,j,m,n,vis,grid,grid[i][j]);
                }
            }
        }
        return maxi;
        
    }
};