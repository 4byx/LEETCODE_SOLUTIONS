class Solution {
public:
    #define ll long long
    int dfs(int curr  , int par  , int * child , vector<int> gr[],int n,ll * ans){
        child[curr] = 1;
        
        int left=-1,right=-1;
        for(auto x : gr[curr]){
            if(x!=par){
                if(left==-1) left = dfs(x,curr,child,gr,n,ans);
                else if(right==-1) right = dfs(x,curr,child,gr,n,ans);
            }
        }
        int leftchild = ((left!=-1)?left:0);
        int rightchild = ((right!=-1)?right:0);
        
        child[curr] +=  leftchild + rightchild;
        
        int score_of_left = (left!=-1)?left:1; // val of left
        int score_of_right = (right!=-1)?right:1; // val of right
        int score_of_parent = max(n-1-leftchild-rightchild , 1); //val of parent subtree 
        
        
        ans[curr] = 1ll*score_of_left*score_of_right*score_of_parent;
        return child[curr];
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> gr[n];
        
        for(int i = 1 ; i < n ; i++){
            gr[i].push_back(parents[i]);
            gr[parents[i]].push_back(i);
        }
        int child[n]; // child array to calculate the children of nodes
        ll ans[n]; // calculating score of each node
        
        // init them with 0
        memset(ans,0,sizeof(ans));
        memset(child,0,sizeof(child));
        
        // dfs
        child[0] = dfs(0,-1,child,gr,n,ans);
        
        
        // maximum score in tree
        ll maxi = INT_MIN;
        for(int i = 0 ; i < n; i++){
            if(ans[i]>maxi) maxi = ans[i];
        }
        
        
        // calculating count of the maximum score
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            if(ans[i]==maxi) res++;
        }
        
        return res;
    }
};