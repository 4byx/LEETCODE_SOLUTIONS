#define LINF 			1e18
#define INF  			1e9
#define NINF 			-1e18
#define F    			first
#define S   			second
#define vi 				vector<int>
#define pi   			pair<int,int>
#define pb   			push_back
#define vvi  			vector<vi>
#define vpi     		vector<pi>
#define si   			set<int>
#define spi  			set<pi>
#define mii  			map<int,int>
#define mpi  			map<pi,int>
#define double 			long double
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define double          long double
#define que_max         priority_queue <int>
#define que_min         priority_queue <int, vi, greater<int>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for(auto x : a) cout << x << " "; cout << endl
#define print1(a)       for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)   for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define endl "\n"
#define repi(s,e) for(int i = s ; i <= e ; i++)
#define repj(s,e) for(int j = s ; j <= e ; j++)


class Solution {
public:
    int dp[400][400];
    int helper(vi &arr , int i , int j) {
        if (j < i) {
            return 0;
        }
        if (j == i) {
            return arr[i - 1] * arr[i] * arr[i + 1];
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = INT_MIN;
        for (int k = i ; k <= j ; k++) {
            int curr = helper(arr, i, k - 1) + helper(arr, k + 1, j);
            curr += arr[k] * arr[i - 1] * arr[j + 1];
            ans = max(ans, curr);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vi arr;
        arr.pb(1);
        int n = nums.size();
        repi(0, n - 1) {
            arr.pb(nums[i]);
        }
        memset(dp,-1,sizeof(dp));
        arr.pb(1);
        n += 2;
        int ans = helper(arr, 1, n - 2);
        return ans;
    }
};