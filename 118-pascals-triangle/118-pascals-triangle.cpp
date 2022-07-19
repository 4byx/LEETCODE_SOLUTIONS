class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> ans = {{1}};
        int n = numRows;
        for(int i = 2 ; i <= n ; i++){
            vector<int> irr;
            irr.push_back(1);
            for(int j = 1 ; j < i-1 ; j++){
                irr.push_back(ans[i-2][j]+ans[i-2][j-1]);
            }
            irr.push_back(1);
            ans.push_back(irr);
        }
        return ans;  
    }
};