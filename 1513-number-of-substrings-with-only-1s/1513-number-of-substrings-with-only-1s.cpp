class Solution {
public:
    int numSub(string s) {
        int cnt = 0;
        int mod = 1e9 + 7;
        int i = 0 , j = 0;
        int n = s.length();
        
        while(j<n){
            while(s[j]!='1' and j<n){
                j++;
                i=j;
            }
            if(j==n) break;
            cnt = cnt%mod + (j-i+1)%mod;
            j++;
            
        }
        return cnt%mod;
    }
};