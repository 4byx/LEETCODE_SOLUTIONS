class Solution {
public:
    int dp[101][101][21];
    int helper(vector<int>& houses , vector<vector<int>>&cost , int m , int n,int target ,int i,int color , int cnt){
        if(i==m){
            if(cnt==target){
                return 0;
            }else{
                return INT_MAX;
            }
        }else if(cnt>target){
            return INT_MAX;
        }
        if(dp[i][cnt][color]!=-1){
            return dp[i][cnt][color];
        }
        int ans = INT_MAX;
        if(houses[i]){
            int newcount = cnt + (houses[i]!=color);
            int subp = helper(houses,cost,m,n,target,i+1,houses[i],newcount);
            if(subp!=INT_MAX){
                ans = min(ans,subp);
            }
        }else{
            for(int j = 0 ; j < n ; j++){
                int newcount = cnt + ((j+1)!=color);
                int subp = helper(houses,cost,m,n,target,i+1,j+1,newcount);
                if(subp!=INT_MAX){
                    ans = min(ans,cost[i][j]+subp);
                }   
            }
        }
        return dp[i][cnt][color] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = helper(houses,cost,m,n,target,0,0,0);
        return (ans==INT_MAX)?-1:ans;
    }
};