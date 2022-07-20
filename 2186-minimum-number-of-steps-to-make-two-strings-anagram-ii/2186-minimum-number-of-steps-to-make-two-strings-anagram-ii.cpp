class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        for(auto x : s){
            freq[x-'a']++;
        }
        for(auto x : t){
            freq[x-'a']--;
        }
        int cnt = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i]) cnt+=abs(freq[i]);
        }
        return cnt;
    }
};