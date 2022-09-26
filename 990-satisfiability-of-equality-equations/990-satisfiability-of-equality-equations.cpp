class Solution {
public:
    int find_parent(int a, int * parent){
        
        if(parent[a] == -1) return a;
        
        return parent[a] = find_parent(parent[a],parent);
    }
    
    void set_union(int a, int b , int * parent , int * rank){
        int p1 = find_parent(a,parent);
        int p2 = find_parent(b,parent);
        
        if(rank[p1] >= rank[p2]){
            rank[p1] += rank[p2];
            parent[p2] = p1;
        }else{
            rank[p2] += rank[p1];
            parent[p1] = p2;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int * parent = new int[26];
        int * rank = new int[26];
        for(int i = 0 ; i < 26 ; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
        sort(equations.begin(),equations.end(),[](string &a , string &b){
            return a[1]>b[1];
        });
        
        for(auto &s : equations){
            // cout<<s<<" ";
            int p1 = find_parent(s[0]-'a' , parent);
            int p2 = find_parent(s[3]-'a' , parent);
            
            if(p1 == p2 and s[1] == '!') return false;
            else if(p1!=p2 and s[1]=='=') set_union(s[0]-'a',s[3]-'a',parent,rank);
        }
        return true;
    }
};