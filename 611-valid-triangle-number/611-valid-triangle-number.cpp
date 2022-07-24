class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = i +1 ; j < n-1 and nums[i] != 0; j++){
                int lb = upper_bound(nums.begin(),nums.end(),nums[i]+nums[j]-1)-nums.begin()-1;
                if(lb!=n){
                    // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[lb]<<"\n";
                ans += lb-j;}
            }
        }
        return ans;
    }
};