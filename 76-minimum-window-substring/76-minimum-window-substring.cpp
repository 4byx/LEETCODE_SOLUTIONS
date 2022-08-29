class Solution {
public:
    bool valid(map<char,int> &ref , map<char,int> &win){
        for(auto x : ref){
            if(win[x.first] < ref[x.first]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> ref;
        for(auto x : t){
            ref[x]++;
        }
        map<char,int> win;
        
        int i =0 , j = 0;
        int n = s.length();
        int mini = INT_MAX;
        pair<int,int> p = {-1,-1};
        while(j<n){
            if(ref.count(s[j])) win[s[j]]++;
            while(valid(ref,win) and i <= j){
                if(ref.count(s[j])) win[s[i]]--;
                if(j-i+1 < mini){
                    mini = j-i+1;
                    p = {i,j};
                }
                i++;
            }
            j++;
        }
        if(mini == INT_MAX) return "";
        string ans = s.substr(p.first,p.second-p.first+1);
        return ans;
    }
};