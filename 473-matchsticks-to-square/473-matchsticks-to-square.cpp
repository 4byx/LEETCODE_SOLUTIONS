class Solution {
public:
    bool helper(vector<int>& ms , int i , vector<int> &len , int &side){
        if(i==(int)ms.size()){
            
            if(len[0]==len[1] and len[1]==len[2] and len[2] == len[3]) return true;
            return false;
        }
        for(int j = 0 ; j < 4 ; j++){
            if(len[j]+ms[i] <= side){
                len[j] += ms[i];
                bool subp = helper(ms,i+1,len,side);
                if(subp) return true;
                len[j] -= ms[i];
            }
        }
        return false;
        
    }
    bool makesquare(vector<int>& ms) {
        int sum = 0;
        for(auto x : ms) sum += x;
        if((sum)%4 != 0) return false;
        sort(ms.begin(),ms.end(),greater<int>());
        int side = sum/4;
        vector<int> len(4,0);
        bool ans = helper(ms,0,len,side);
        return ans;
    }
};