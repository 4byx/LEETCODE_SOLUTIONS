class Solution {
public:
    int dp[501][501];
    int helper(vector<int>& sa , int i ,int t, int n){
        if(i==n) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int ntaken = helper(sa,i+1,t,n);
        int taken = sa[i]*t + helper(sa,i+1,t+1,n);
        return dp[i][t] = max(taken,ntaken);
    }
    int maxSatisfaction(vector<int>& sa) {
        int n = sa.size();
        sort(sa.begin(),sa.end());
        memset(dp,-1,sizeof(dp));
        int ans = helper(sa,0,1,n);
        return ans;
    }
};