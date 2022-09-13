class Solution {
    int get_idx(int st , int end , vector<vector<int>> &events , int target){
        int idx = events.size() , left = st , right = end;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            
            if(events[mid][0] > target){
                idx = mid;
                right = mid - 1;
            }else
                left = mid + 1;
        }
        
        return idx;
    }
    
    int get_mx_val(int idx , vector<vector<int>> &events , int k , vector<vector<int>> &dp){
        if(idx == events.size())
            return 0;
        
        int case1 = 0 , case2 = 0;
        
        if(dp[k][idx] != -1)
            return dp[k][idx];
        
        // to take
        if(k > 0){
           int next_idx = get_idx(idx + 1 , events.size() - 1 , events , events[idx][1]);
           case1 += events[idx][2] + get_mx_val(next_idx , events , k - 1 , dp);
        }
        
        // to no take
        case2 = get_mx_val(idx + 1 , events , k , dp);
        
        return dp[k][idx] = max(case1 , case2);
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        int n = events.size();
        
        vector<vector<int>> dp(k + 1 , vector<int>(n + 1 , -1));
        
        return get_mx_val(0 , events , k , dp);
    }
};