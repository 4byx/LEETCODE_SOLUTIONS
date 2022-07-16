class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = -1;
        int n = cards.size();
        int i = 0 , j = 0;
        unordered_map<int,int> m;
        while(i<n){
            m[cards[i]]++;
            if(m[cards[i]]==2){
                while(j<i and m[cards[i]]!=1){
                    m[cards[j]]--;j++;
                }
                if(ans==-1){
                    ans = i-j+2;
                }else{
                    ans = min({ans,i-j+2});
                }
            }
            i++;
        }
        return ans;
    }
};