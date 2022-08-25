class Solution {
public:
    int dp[1000][1000];
    int helper(string &s , string &t,int i , int j,int n , int m){
        if(i==n){
            if(j==m) return 1;
            return 0;
        }
        if(j==m){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
            ans += helper(s,t,i+1,j+1,n,m);
        }
        ans += helper(s,t,i+1,j,n,m);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        int m = t.length();
        int ans = helper(s,t,0,0,n,m);
        return ans;
    }
};