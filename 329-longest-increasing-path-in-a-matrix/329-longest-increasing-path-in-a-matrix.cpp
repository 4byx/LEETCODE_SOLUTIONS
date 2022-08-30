class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        
        int m = matrix.size() , n = matrix[0].size();
        map<pair<int,int>,int> indegree;
         for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
               indegree[{i,j}] = 0; 
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                for(int k = 0 ; k < 4 ; k++){
                    int x = i+dx[k] , y = j+dy[k];
                    if(x>=0 and x<m and y>=0 and y<n and matrix[x][y] > matrix[i][j]){
                        indegree[{x,y}]++;
                    }
                    
                }
                
            }
        }
        int ans = 1;
        vector<int> dep(m*n,0);
        queue<pair<int,int>> q;
        
        for(auto x : indegree){
            if(indegree[x.first] == 0){
                q.push(x.first);
                // cout<<x.first.first<<" ";
                dep[x.first.first * n + x.first.second] = 1;
            } 
        }
        
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            // cout<<i<<" "<<j<<"\n";
            int par = i*n + j;
            for(int k = 0 ; k < 4 ; k++){
                    int x = i+dx[k] , y = j+dy[k];
                    if(x>=0 and x<m and y>=0 and y<n and matrix[x][y] > matrix[i][j]){
                        int cnt = x*n + y;
                        indegree[{x,y}] -= 1;
                        dep[cnt] = dep[par]+1;
                        if(indegree[{x,y}] == 0){
                            ans = max({ans,dep[cnt]});
                            q.push({x,y});
                        }
                    }
            }
        }
        return ans;
    }
};