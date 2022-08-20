class Solution {
public:
    string s="";
	// memo all the states, maximum 10 digits, and 1024 is the max mask value
    int dp[11][2][2][1500]; 
	// last will tell about the number placed previously is last limit or not
	// zero is used to avoid trailing zero
	// if we have trailing zero then we will not mark 0'th bit set
    int solve(bool last, int in, int mask, bool zero){ 
        if(in==s.size()) return 1;
        if(dp[in][last][zero][mask]!=-1) return dp[in][last][zero][mask];
        int till=(last?(s[in]-'0'):9);
        int ct=0;
        for(int i=0; i<=till; i++){
            if(!(mask&(1<<i))){ // checking if i'th bit set or not
				// if 0 is available abd last digit was also zero then we will not set it
                if(i==0 && !zero) mask=mask|(1<<i); 
                if(i!=0) mask=mask|(1<<i);
                ct+=solve((last&&(i==till)), in+1, mask, (i==0&&zero));
                mask=mask&(~(1<<i)); // backtracking
            }
        }
        return dp[in][last][zero][mask]=ct;
    }
    int countSpecialNumbers(int n) {
        s=to_string(n);
        string ans="";
        int mx=(2<<8);
        int mask=0;
        if(s.size()==1){
            return n;
        }
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, mask, 1)-1;
    }
};