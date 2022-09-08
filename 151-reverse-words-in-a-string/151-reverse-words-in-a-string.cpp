class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string ans = "";
        string temp = "";
        while(str >> temp){
            ans = ' ' + temp + ans;
        }
        return ans.substr(1,ans.size()-1);
    }
};