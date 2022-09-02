class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        map<int,vector<int>> m;
        
        for(int i = 0 ; i < n ; i++){
            m[arr[i]].push_back(i);
        }
        
        
        vector<int> vis(n,INT_MAX);
        vis[0] = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top==n-1) return vis[top];
            
            if(top+1<n and vis[top+1] == INT_MAX){
                vis[top+1] = vis[top]+1;
                q.push(top+1);
            }
            if(top-1>=0 and vis[top-1] == INT_MAX){
                vis[top-1] = vis[top]+1;
                q.push(top-1);
            }
            for(auto x : m[arr[top]]){
                if(x!=top and vis[x] == INT_MAX){
                    vis[x] = vis[top]+1;
                    q.push(x);
                }
            }
            m[arr[top]] = {};
        }
        return 0;
    }
};