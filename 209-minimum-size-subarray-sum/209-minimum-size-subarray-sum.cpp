class Solution {
public:
    bool helper(vector<int> &temp, int mid , int target){
        int n = temp.size();
        for(int i = 0 ; i <= n-mid-1 ; i++){
            if((temp[i+mid]-temp[i])>=target) return true;
        }
        return false;
        
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp(n+1);
        temp[0]=0;
        temp[1] = nums[0];
        
        for(int i = 2 ; i <= n ; i++){
            temp[i] = nums[i-1]+temp[i-1];
        }
        int low = 0;
        int high = n;
        int ans = 0;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            // cout<<mid<<" ";
            bool check = helper(temp,mid,target);
            
            if(check){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        return ans;
    }
};