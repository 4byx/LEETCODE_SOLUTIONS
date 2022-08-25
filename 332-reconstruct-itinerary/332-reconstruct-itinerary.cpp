class Solution {
public:
    void dfs(string curr , map<string,multiset<string>> &gr , vector<string> &path){
        
        while(gr[curr].size()){
            string str = *(gr[curr].begin());
            gr[curr].erase(gr[curr].begin());
            dfs(str,gr,path);
        }
        path.push_back(curr);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>> gr;
        for(auto x : tickets){
            gr[x[0]].insert(x[1]);
        }
        
        vector<string> path;
        
        dfs("JFK",gr,path);
        reverse(path.begin(),path.end());
        return path;
    }
};