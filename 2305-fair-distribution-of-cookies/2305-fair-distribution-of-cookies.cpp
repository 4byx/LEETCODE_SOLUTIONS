class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<int> &cookies, vector<int> &temp,int i , int &n,int maxx){
        if(i==n){
            ans = min({maxx,ans});
            return;
        }
        
        
        for(int j = 0 ; j < temp.size() ; j++){
            temp[j] += cookies[i];
            helper(cookies,temp,i+1,n,max({maxx,temp[j]}));
            temp[j] -= cookies[i];
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k,0);
        int n = cookies.size();
        helper(cookies,temp,0,n,0);
        return ans;
    }
};