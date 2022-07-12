    static int dx[4] = {0,0,1,-1};
    static int dy[4] = {1,-1,0,0};
class Solution {
public:
    
    int bfs(vector<vector<vector<int>>> graph, int m , int n){
        queue<pair<int,int>> q;
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        q.push({0,0});
        dis[0][0] = 0;
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int k = 0 ; k < 4 ; k++){
                int xx = x + dx[k];
                int yy = y + dy[k];
                
                if(xx>=0 and xx<m and yy>=0 and yy<n and dis[x][y] + (graph[x][y][k]) < dis[xx][yy]){
                    dis[xx][yy] = dis[x][y] + (graph[x][y][k]);
                    int difx = xx-x;
                    int dify = yy-y;                                          
                    q.push({xx,yy});
                }
            }
        }
        return dis[m-1][n-1];
    }
    
    
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> graph (m,vector<vector<int>>(n));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                vector<int> v(4,1);
                v[grid[i][j]-1] = 0;
                graph[i][j] = v;
            }
        }
        
        int ans = bfs(graph,m,n);
        return ans;
    }
};