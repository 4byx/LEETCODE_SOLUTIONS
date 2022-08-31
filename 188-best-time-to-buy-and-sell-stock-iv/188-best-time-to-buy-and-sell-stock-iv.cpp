class Solution {
public:
    int dp[1001][101][2];
    int helper(int i , bool buy , int k , vector<int> &prices){
        
        if(i == prices.size()) return 0;
        if(k==0) return 0;
        if(dp[i][k][buy]!=-1) return dp[i][k][buy];
        int ans = helper(i+1,buy,k,prices);
        if(buy){
            ans = max({ans,-prices[i] + helper(i+1,false,k,prices)});
        }else{
            ans = max({ans,prices[i] + helper(i+1,true,k-1,prices)});
        }
        return dp[i][k][buy]=  ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int ans = helper(0,true,k,prices);
        return ans;
    }
};