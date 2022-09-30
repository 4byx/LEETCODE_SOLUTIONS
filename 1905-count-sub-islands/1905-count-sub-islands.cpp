int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
class Solution {
public:
    int subans;
    void dfs(int i , int j , vector<vector<int>>& grid1, vector<vector<int>>& grid2,int m , int n){
        grid1[i][j] = grid2[i][j] = -1;
        
        
        for(int k = 0 ; k < 4 ; k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            if(xx >=0 and xx<m and yy>=0 and yy<n){
                if(grid1[xx][yy]==1 and grid2[xx][yy]==1) dfs(xx,yy,grid1,grid2,m,n);
                else if(grid1[xx][yy]!=1 and grid2[xx][yy]==1) subans = false;
            }
        }
        
        grid1[i][j] = grid2[i][j] = 2;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int m = grid1.size();
        int n = grid1[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid1[i][j] == 1 and grid2[i][j] == 1){
                    subans = true;
                    dfs(i,j,grid1,grid2,m,n);
                    if(subans) ans++;
                }
            }
        }
        return ans;
    }
};