class Solution {
public:
    int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return nums[0];
		int i2 =  nums[0];
		int i1 = max(nums[0], nums[1]);

		for (int i = 2 ; i < n; i++ ) {
            int temp = i1;
			i1 = max(i2 + nums[i], i1);
            i2 = temp;
		}
		return max(i1,i2);
	}
};