class Solution:
    
    def recur(self,nums,i,n,arr):
        if(i>(n-1)):
            return 0
        
        if(arr[i]!=-1):
            return arr[i]
        
        # 1 2 3 1
          
        op1 = nums[i] + self.recur(nums,i+2,n,arr)
        op2 = self.recur(nums,i+1,n,arr)
        arr[i] = max(op1,op2)
        return arr[i]
        
    def rob(self, nums: List[int]) -> int:
        arr = [-1]*101
        n = len(nums)
        ans = self.recur(nums,0,n,arr)
        return ans
        