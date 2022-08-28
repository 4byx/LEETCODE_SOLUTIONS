class Solution {
public:
    string ss;
    int dp[2001];
    bool ispalindrome(int i , int j){
        while(i<=j){
            if(ss[i]!=ss[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    int helper(int i){
        int n = ss.length();
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        
        int ans = INT_MAX;
        for(int j = i ; j < n ; j++){
            if(ispalindrome(i,j)) ans = min({ans,1+helper(j+1)});
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        ss = s;
        int ans = helper(0);
        return ans-1;
    }
};