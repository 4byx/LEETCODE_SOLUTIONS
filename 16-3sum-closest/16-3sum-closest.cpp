class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
 
        int n = nums.size();
       long long ans = INT_MIN;
        long long val1 =  INT_MIN;
        for(int i=0;i<n;i++){
           int j = i+1;
                int k = n-1;
                // cout<<i<<" "<<j<<"\n";
                 long long val = INT_MIN;
                while(j<k){
                     val = nums[i] +nums[j]+nums[k];
           
                    if(val<target){
                        j++;
                    }
                    else if(val>target){
                        k--;
                    }
                    else{
                                
                        return target;
                    }
             
                    
                }
               
                 if(abs(target-ans)>abs(target-val)){
                          
                    ans = val;
                }
            
          
        }
        return ans;
    }
};