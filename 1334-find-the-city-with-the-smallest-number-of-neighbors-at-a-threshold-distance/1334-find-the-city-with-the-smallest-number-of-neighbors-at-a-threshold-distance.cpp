class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for(auto x : edges){
            dis[x[0]][x[1]] = dis[x[1]][x[0]] = x[2];
        }
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(dis[i][k]!=INT_MAX 
                       and dis[k][j]!=INT_MAX and dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                    }
                }
            }
        }
        int cnt = n+1 , idx = -1;
        for(int i = 0 ; i < n ; i++){
            int subans = 0;
            for(int j = 0 ; j < n ; j++){
                if(i!=j and dis[i][j] <= dt){
                    subans++;
                }
            }
            if(subans <= cnt){
                cnt = subans;
                idx = i;
            }
        }
        return idx;
    }
};