class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0 , ans = 0;
        
        int n = bank.size();
        for(int i = 0 ; i < n ; i++){
            int subcnt = 0;
            for(auto x : bank[i]){
                subcnt += (x=='1')?1:0;
            }
            ans += cnt*subcnt;
            cnt = (subcnt==0)?cnt:subcnt;
        }
        return ans;
    }
};