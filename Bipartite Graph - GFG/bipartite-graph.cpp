//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int curr , vector<int> adj[] , vector<int> &vis , int color,int parent) {
        vis[curr] = color;
        for(auto x : adj[curr]) {
            if(!vis[x]) {
                bool subans = dfs(x,adj,vis,3-color,curr);
                if(!subans) return false;
            }else if(x!=parent and vis[x] == color) {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V,0);
	    for(int i = 0 ; i < V ; i++){
	        if(!vis[i]) {
	            bool subans = dfs(i,adj,vis,1,-1);
	            if(!subans) return false;
	        }
	    } 	 
	    return true;// Code here
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends