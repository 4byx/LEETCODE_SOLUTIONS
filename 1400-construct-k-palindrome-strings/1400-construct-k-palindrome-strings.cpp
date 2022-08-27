class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int> m;
        if(s.length() < k) return false;
        for(auto x : s) m[x]++;
        int len = 0;
        for(auto x : m){
            len += x.second%2;
        }
        
        if(len <= k) return true;
        return false;
    }
};