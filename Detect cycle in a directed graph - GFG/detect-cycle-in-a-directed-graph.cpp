//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int curr , vector<int> adj[] , vector<int> &vis , vector<int> &stack){
        vis[curr] = stack[curr] = 1;
        
        for(auto x : adj[curr]){
            if(!vis[x]){
                bool subans = dfs(x,adj,vis,stack);
                if(subans) return true;
            }else if(stack[x]){
                return true;
            }
        }
        stack[curr] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0) , stack(V,0);
        
        bool ans = false;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i])
            ans |= dfs(i,adj,vis,stack);
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends