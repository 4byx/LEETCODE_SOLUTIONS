class Solution {
public: 
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector<vector<int>> vis(6000,vector<int>(2,0));
        for(auto x : forbidden) vis[x][0]=vis[x][1]=1;
        
        queue<pair<int,int>> Q;
        Q.push({0,1});
        vis[0][0]=vis[0][1]=1;
        int cnt = 0;
        while(!Q.empty()){
            int len = Q.size();
            while(len--){
                auto [node,isback] = Q.front();   Q.pop();
                if(node==x) return cnt;
                int forward = node+a;
                int backward = node-b;

                if(forward < 6000 and !vis[forward][0]){
                    vis[forward][0]=1;
                    Q.push({forward,0});
                }
                if(backward > 0 and !vis[backward][1] and !isback){
                    vis[backward][1]=1;
                    Q.push({backward,1});
                }
            }
            cnt++;
        }
        return -1;
    }
};