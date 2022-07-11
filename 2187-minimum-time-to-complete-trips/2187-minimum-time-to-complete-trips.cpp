class Solution {
public:
    #define ll long long
    long long helper(vector<int>& time , long long mid){
        long long ans = 0;
        for(auto x : time){
            ans += (mid/x);
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int tt) {
        long long ans = 0;
        int n = time.size();
        long long low = 1;
        long long high = 1ll*time[0]*tt;
        
        while(low<=high){
            
            long long mid = low + (high-low)/2;
            
            long long check = helper(time,mid);
            
            if(check>=tt){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};