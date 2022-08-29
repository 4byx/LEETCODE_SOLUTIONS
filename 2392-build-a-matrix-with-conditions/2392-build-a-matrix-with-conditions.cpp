class Solution {
public:
    bool dfs1(int curr , vector<int> &vis , vector<int> &top1 , vector<int> rgr[]){
        vis[curr]=2;
        
        for(auto x : rgr[curr]){
            if(vis[x] == 0){
                int subans = dfs1(x,vis,top1,rgr);
                if(subans) return true;
            }else if(vis[x]==2) return true;
        }
        vis[curr]=1;
        top1.push_back(curr);
        return false;
    }
    bool dfs2(int curr , vector<int> &vis2 , vector<int> &top2 , vector<int> cgr[]){
        vis2[curr]=2;
        
        for(auto x : cgr[curr]){
            if(vis2[x] == 0){
                int subans = dfs2(x,vis2,top2,cgr);
                if(subans) return true;
            }else if(vis2[x]==2) return true;
        }
        vis2[curr]=1;
        top2.push_back(curr);
        return false;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rgr[k+1] , cgr[k+1];
        
        for(auto x : rowConditions){
            rgr[x[0]].push_back(x[1]);
        }
        for(auto x : colConditions){
            cgr[x[0]].push_back(x[1]);
        }
        
        vector<int> vis(k+1,0);
        vector<int> top1,top2;
        bool check1 = false;
        for(int i =1 ; i <= k ; i++){
            if(!vis[i] and !check1) check1 |= dfs1(i,vis,top1,rgr);
        }
        if(check1) return {};
        vector<int> vis2(k+1,0);
        for(int i =1 ; i <= k ; i++){
            if(!vis2[i] and !check1) check1 |= dfs2(i,vis2,top2,cgr);
        }
        if(check1) return {};
        
        reverse(top1.begin(),top1.end());
        reverse(top2.begin(),top2.end());
        // for(auto x : top1) cout<<x<<" ";
        // for(auto x : top2) cout<<x<<" ";

        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i = 0 ; i < k;  i++){
            for(int j = 0 ; j < k ; j++){
                if(top1[i]==top2[j]){
                    ans[i][j] = top1[i];
                }
            }
        }
        return ans;
        
        
        
    }
};