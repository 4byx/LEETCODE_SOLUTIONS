class Solution {
public:
    int dp[300];
    bool helper(string &s , set<string>&st , int i , int n){
        if(i>=n) return true;
        if(dp[i]!=-1) return dp[i];
        int ans = false;
        for(int idx = 1 ;i+idx <= n ; idx++){
            ans |= (st.count(s.substr(i,idx))==1)&&(helper(s,st,i+idx,n));
        }
        return dp[i] = ans;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp,-1,sizeof(dp));
        for(auto x : wordDict){
            st.insert(x);
        }
        int n = s.size();
        bool ans = helper(s,st,0,n);
        return ans;
    }
};