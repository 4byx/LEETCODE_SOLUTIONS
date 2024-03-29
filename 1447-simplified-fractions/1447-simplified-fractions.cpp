class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        
        vector<string> ans;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j < i ; j++){
                if(__gcd(i,j)==1){
                    string s = to_string(j)+"/"+to_string(i);
                    ans.push_back(s);
                }
            }
        }
        return ans;
        
    }
};