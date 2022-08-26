class Solution {
public:
    int memo[601][101][101];
    int helper(int i , int one , int zero , int m , int n , int dp[][2] , int sz){
        if(i==sz){
            if(zero <= m and one <= n ) return 0;
            return INT_MIN;
        }
        if(memo[i][one][zero]!=-1) return memo[i][one][zero];
        int ans = INT_MIN;
        if(zero + dp[i][0] <= m and one + dp[i][1] <= n){
            int subans = helper(i+1,one+dp[i][1],zero+dp[i][0],m,n,dp,sz);
            if(subans!=INT_MIN){
                ans = max({ans,1+subans});
            }
        }
        ans = max({ans,helper(i+1,one,zero,m,n,dp,sz)});
        return memo[i][one][zero] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        int dp[sz][2];
        memset(dp,0,sizeof(dp));
        memset(memo,-1,sizeof(memo));
        int cnt = 0;
        for(auto x : strs){
            for(auto y : x){
                if(y=='0') dp[cnt][0]++;
                else dp[cnt][1]++;
            }
            cnt++;
        }
        int ans = helper(0,0,0,m,n,dp,sz);
        return ans==INT_MIN ? 0 : ans;
    }
};