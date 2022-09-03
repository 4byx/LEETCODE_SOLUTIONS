class Solution {
public:
    vector<int> res;
    
    void helper(int i , int n , int k , string ans,int last){
        if(i==n){
            int x = stoi(ans);
            res.push_back(x);
            return;
        }
        
        for(int j = 0 ; j <= 9 ; j++){
            if(i==0){
                if(j!=0){
                    ans += to_string(j);
                    helper(i+1,n,k,ans,j);
                    ans.pop_back();
                }
            }else{
                if(abs(j-last)==k){
                    ans += to_string(j);
                    helper(i+1,n,k,ans,j);
                    ans.pop_back();
                }
            }
        }
        return;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        string ans = "";
        helper(0,n,k,ans,-1);
        return res;
    }
};