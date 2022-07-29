int X;
class Solution {
public:
    static bool compare(int &a, int &b){
        if(abs(X-a) == abs(X-b)){
            if(a<b)return true ;
            return false;
        }
        return abs(X-a) < abs(X-b);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x){ 
        X = x;
        sort(arr.begin(),arr.end(),compare);
        vector<int> temp;
        int cnt = 0;
        while(cnt < k){
            temp.push_back(arr[cnt]);
            cnt++;
        }
        sort(temp.begin(),temp.end());
    return temp;
    }
};