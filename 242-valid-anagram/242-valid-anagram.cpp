class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        for(auto x : s) m1[x]++;
        for(auto x : t) m2[x]++;
        return m1==m2;
    }
};