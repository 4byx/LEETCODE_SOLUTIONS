class Solution {
public:
    
    class DSU{
      public:
        int n;
        int * parent;
        int * rank;
        
        DSU(int _n){
            n = _n+1;
            parent = new int[n+1];
            rank = new int[n+1];
            
            for(int i = 1; i <= n ; i++){
                rank[i]=1;
                parent[i]=-1;
            }
        }
        
        int find(int u){
            if(parent[u]==-1){
                return u;
            }
            return parent[u] = find(parent[u]);
        }


        bool uni(int u , int v){
            int p1 = find(u);
            int p2 = find(v);
            if(p1==p2) return false;
            if(rank[p1] >= rank[p2]){
                rank[p1] += rank[p2];
                parent[p2] = p1;
            }else{
                rank[p2] += rank[p1];
                parent[p1] = p2;
            }
            return true;
        }
    };
    
    
    vector<int> detect(vector<vector<int>> &edges, int n , vector<int> edge){
        DSU ds(n);
        for(auto x : edges){
            if(x==edge){ continue;}
            if(!ds.uni(x[0],x[1])) return x;
        }
        return {};
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // indegree with two
        int two = -1;
        vector<int> ind(n+1,0);
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            ind[v]++;
            if(ind[v]>1){
                two = v;
                break;
            }
        }
        
        if(two == -1) return detect(edges,n,{-1,-1});
        
        for(int i = n-1 ; i>= 0 ;i--){
            vector<int> x = edges[i];
            int u = x[0];
            int v = x[1];
            
            if(v==two){
               vector<int> out = detect(edges,n,{u,v});
               if(out.size()==0) return x;
            }
        }
        return {-1,-1};
    }
};