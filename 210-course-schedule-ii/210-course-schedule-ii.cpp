class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        int ind[n];
        vector<int> gr[n];
        memset(ind,0,sizeof(ind));
        
        for(auto x : pre){
            ind[x[0]]++;
            gr[x[1]].push_back(x[0]);
        }
        queue<int> q;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) if(ind[i] == 0) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int top = q.front(); q.pop();
            ans.push_back(top);
            
            for(auto x : gr[top]){
                
                if(--ind[x] == 0) q.push(x);
            }
            cnt++;
        }
        if(cnt != n) return {};
        return ans;
        
    }
};