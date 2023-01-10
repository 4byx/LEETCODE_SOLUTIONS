//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph
    bool  dfs(int curr , vector<int> adj[] , vector<bool> &vis,int parent){
        vis[curr] = true;
        
        for(auto x : adj[curr]){
            if(!vis[x]){
                bool ans = dfs(x,adj,vis,curr);
                if(ans){
                    return true;
                }
            }else if(x!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        bool ans = false;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                ans |= dfs(i,adj,vis,-1);
            }
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends