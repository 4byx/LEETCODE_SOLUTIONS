class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        map<int,int> m;
        int n = nums.size();
        int sum = 0;
        m[0]++;
        for(auto x : nums){
            sum += x;
            while(sum < 0) sum += k;
            ans += m[sum%k];
            m[sum%k]++;
        }
        return ans;
    }
};