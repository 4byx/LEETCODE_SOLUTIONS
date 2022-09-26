class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        
        vector<long long> ps1(n,0) , ps2(n,0);
        ps1[0] = grid[0][0];
        ps2[0] = grid[1][0];
        for(int i = 1 ; i < n ; i++){
            ps1[i] = grid[0][i] + ps1[i-1];
            ps2[i] = grid[1][i] + ps2[i-1];
        }
        
        long long maxi = 0 , ans = 1e18;
        
        for(int i = 0 ; i < n ; i++){
            // long long sub = ps1[i] + ps2[n-1] - (i-1>=0 ?(ps2[i-1]): 0);
            // if(sub > maxi){
            //     maxi = sub;
                ans = min({ans,max(ps1[n-1] - ps1[i],i-1>=0 ?(ps2[i-1]): 0)});
            // }
        }
        return ans;
    }
};