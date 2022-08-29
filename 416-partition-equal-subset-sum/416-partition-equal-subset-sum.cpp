class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums){
            sum += x;
        }
        if(sum%2 == 1){
            return false;
        }
        sum /= 2;
        int n = nums.size();
        int dp[n+1][sum+1];
        
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= sum ; j++){
                if(j==0){
                    dp[i][j]=1;
                }else{
                    dp[i][j] = dp[i-1][j] || ((j-nums[i-1] >= 0) ? dp[i-1][j-nums[i-1]] : 0);
                }
            }
        }
        return dp[n][sum];
    }
};