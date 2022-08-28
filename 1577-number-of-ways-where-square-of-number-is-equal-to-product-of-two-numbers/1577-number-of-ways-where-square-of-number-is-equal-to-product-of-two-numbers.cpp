class Solution {
public:
    #define ll long long
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<ll,ll> m1 , m2;
        int n = nums2.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1; j < n ; j++){
                m1[1ll*nums2[i]*nums2[j]]++;
            }
        }
        int m = nums1.size();
        for(int i = 0 ; i < m ; i++){
            for(int j = i+1; j < m ; j++){
                m2[1ll*nums1[i]*nums1[j]]++;
            }
        }
        
        int ans = 0;
        for(auto x : nums1){
            ll fin = 1ll*x*x;
            ans += m1[fin];
        }
        for(auto x : nums2){
            ll fin = 1ll*x*x;
            ans += m2[fin];
        }
        return ans;
    }
};