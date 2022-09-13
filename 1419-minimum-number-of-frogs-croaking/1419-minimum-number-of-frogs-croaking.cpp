class Solution {
public:
    int minNumberOfFrogs(string cr) {
        unordered_map<char,char> m,freq;
        string s = "croak";
        
        for(int i = 1; i < 5 ; i++){
            m[s[i]] = s[i-1];
        }
        unordered_map<char,int> win;
        int n = cr.length();
        int busy = 0,count = 0;
        for(int i = 0 ; i < n ; i++){
            if(cr[i] == 'c'){
                win[cr[i]]++;
                if(busy == count) count++;
                busy++;
            }else{
                if(win[m[cr[i]]] > 0){
                    win[m[cr[i]]]--;
                    if(win[m[cr[i]]] == 0) win.erase(m[cr[i]]);
                    if(cr[i]!='k') win[cr[i]]++;
                    else busy--;
                }else{
                    return -1;
                }
            }
        }
        for(auto i:win)
        {
            if(i.second>0)
                return -1;
        }
        
        return count;
    }
};