class Solution {
public:
    map<tuple<int,int,int>,long long> m;
    int helper(int i , vector<vector<int>> &events , int k 
               , int n , int end){
        if(i==n or k==0){
            return 0;
        }
        
        if(m.count({i,k,end})){
            return m[{i,k,end}];
        }
        int ans = INT_MIN;
        if(events[i][0] > end){
            ans = max(ans,events[i][2] + helper(i+1,events,k-1,n,events[i][1]));
        }
        ans = max(ans,helper(i+1,events,k,n,end));
        return m[{i,k,end}] = ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end(),[](vector<int> &a , vector<int> &b){
            return a[0] < b[0];
        });
        
        int ans = helper(0,events,k,n,-1);
        return ans;
    }
};