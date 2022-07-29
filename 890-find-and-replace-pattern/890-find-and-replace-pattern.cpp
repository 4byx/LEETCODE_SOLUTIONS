class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        map<char,char> m1;
        map<char,char> m2;
        for(auto x : words){
            m1.clear(); m2.clear();
            int n = x.size();
            bool found = true;
            for(int i = 0 ; i < n ; i++){
                if(m1.count(pattern[i]) and m1[pattern[i]] != x[i])
                {found = false; break;}
                else if(m2.count(x[i]) and m2[x[i]] != pattern[i])
                {found = false; break;}
                else if(m1.count(pattern[i])==0  and m2.count(x[i])==0){
                    m1[pattern[i]] = x[i];
                    m2[x[i]] = pattern[i];
                }
            }
            
            if(found){
                ans.push_back(x);
            }   
        }
        return ans;
    }
};