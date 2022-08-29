class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length();
        st.push(-1);
        int maxans  =0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    maxans = max(maxans,i-st.top());
                }
            }
        }
        return maxans;
    }
};

/*
*/