class Solution {
public:
    #define ll long long
    ll dp[30001];
    ll rec(int idx , vector<vector<int>> &ar){
        int n = ar.size();
        if(idx == n) return 0;
        
        
        if(dp[idx]!=-1) return dp[idx];
        // excluding this position
        ll ans = rec(idx+1,ar);
    
        // including option
        
        int lo = idx+1,hi = n-1 , nextIdx = n;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(ar[mid][0]>=ar[idx][1]){
                nextIdx = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        
        ans = max({ans,ar[idx][2]+rec(nextIdx,ar)});
        return dp[idx] = ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& ar) {
        for(auto &x : ar) x[2] += x[1]-x[0];
        sort(ar.begin(),ar.end());
        memset(dp,-1,sizeof(dp));
        
        ll ans = rec(0,ar);
        return ans;
    }
};