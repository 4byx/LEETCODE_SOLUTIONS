class Solution {
public:
        void helper(vector<int> &arr , int n , vector<int> &v , vector<vector<int>> &ans , int i){
        ans.push_back(v);
        for(int j = i ; j < n ; j++){
            if(j>i and arr[j]==arr[j-1]) continue;
                v.push_back(arr[j]);
                helper(arr,n,v,ans,j+1);
                v.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> v;

        helper(arr,n,v,ans,0);
        return ans;
    }
};