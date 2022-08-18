class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> temp;
        int n = arr.size();
        map<int,int> m;
        
        for(auto x : arr) m[x]++;
        
        for(auto x : m){
            temp.push_back(x.second);
        }
        sort(temp.begin(),temp.end(),greater<int>());
        
        for(int i = 0 ; i < n ; i++){
            if(i!=0){
                temp[i] += temp[i-1];
            }
            if(temp[i]>=((n+1)/2)){
                return i+1;
            }
        }
        return n+1;
        
    }
};