class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        s = t+"#"+s;
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        string front = t.substr(pi[n-1]);
        reverse(front.begin(),front.end());
        return front+t;
    }
};