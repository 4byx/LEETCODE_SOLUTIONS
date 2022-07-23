class Solution {
public:
    string s , p;
    vector<vector<int>> dp; 
    bool helper(int i , int j){
        if(i==s.size() and j==p.size()){
            return true;
        }else if(j==p.size()){
            return false;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(p[j]=='?'){
            if(i==s.size()){
                return false;
            }else{
                ans |= helper(i+1,j+1);
            }
        }else if(i<s.size() and s[i]==p[j]){
            ans |= helper(i+1,j+1);
        }
        else if(p[j]=='*'){
            if(i<s.size()){
                ans |= helper(i+1,j);
            }
            ans |= helper(i,j+1);
        }
        return dp[i][j] = ans;
    }
    
    bool isMatch(string ss, string pp) {
        s = ss;
        p = pp;
        dp.resize(s.size()+1,vector<int>(p.size()+1,-1));
        bool ans = helper(0,0);
        return ans;
    }
};