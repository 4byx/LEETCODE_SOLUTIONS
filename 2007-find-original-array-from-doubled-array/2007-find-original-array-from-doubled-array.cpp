class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> m;
        int n = changed.size();
        if(n%2!=0) return {};
        
        sort(changed.begin(),changed.end());
        
        for(auto x : changed){
            m[x]++;
        }
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(m[changed[i]] > 0 and m[2*changed[i]] > 0){
                m[changed[i]]--;
                m[2*changed[i]]--;
                ans.push_back(changed[i]);
            }
            else if(m[changed[i]]!=0 and m[2*changed[i]]==0){
                return {};
            }
        }
        return ans;
    }
};