class Solution {
public:
    int lowerbound(vector<int> &nums , int &target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int upperbound(vector<int> &nums , int &target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lb = lowerbound(nums,target);
        int ub = upperbound(nums,target);
        
        return {lb,ub};
    }
};