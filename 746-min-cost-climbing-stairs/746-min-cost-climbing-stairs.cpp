class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // size of cost array
        int n = cost.size();
        
        // dp array of size of n+1 because we have to reach top floor which is n
        vector<int> dp(n+1,0);
        
        // we can start with 0 and 1  so dp[i] = cost[i] for i<=1
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        // loop to calculate dp array
        for(int i = 2 ; i <= n ; i++){
            // if i==n then we have reached top floor which we can come from last 2 floors
            if(i==n) dp[i] = min(dp[i-1],dp[i-2]);
            
            // for other floors we have to have to add their cost
            else
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        
        // returning value of top most floor n
        return dp[n];
    }
};