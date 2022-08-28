class Solution {
public:
    map<tuple<int,int>,string> m;
    void helper(int n , string s , vector<string> &ans , int open , int close){
        
        if(n==0){
            while(close<open){
                s+=')';
                close++;
            }
            ans.push_back(s);
            return;
        }
        
        if(close < open) helper(n,s+')',ans,open,close+1);
        helper(n-1,s+'(',ans,open+1,close);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        helper(n,s,ans,0,0);
        return ans;
    }
};