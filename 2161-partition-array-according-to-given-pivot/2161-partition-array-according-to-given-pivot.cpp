class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> gt;
        int j , cnt = 0 , i = 0;
        for(j=0;j<n;j++){
            if(nums[j]<pivot) nums[i++] = nums[j];
            else if(nums[j]==pivot) cnt++;
            else gt.push_back(nums[j]);
        }
        
        while(cnt--) nums[i++] = pivot;
        for(auto x : gt) nums[i++]=x;
        return nums;
    }
};