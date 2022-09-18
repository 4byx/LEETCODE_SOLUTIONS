struct Node{
    char d;
    unordered_map<char,Node*> m;
    bool isterminal;
    int cnt;
    
    Node(char _d){
        d = _d;
        isterminal = false;
        cnt = 0;
    }
};

struct Trie{
    Node * root;
    
    
    Trie(){
        root = new Node('\0');
    }
    
    void add(string word){
        Node * temp = root;
        
        for(auto x : word){
            if(temp->m.count(x) == 0){
                Node * n = new Node(x);
                temp->m[x] = n;
            }
            temp = temp->m[x];
            temp->cnt += 1;
        }
        temp->isterminal = true;
    }
    
    int search(string word){
       Node * temp = root;
        int ans = 0;
        for(auto x : word){
            if(temp->m.count(x) == 0){
                return 0;
            }
            temp = temp->m[x];
            ans += temp->cnt;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        
        for(auto x : words) t.add(x);
        map<char,int> m;
        
        vector<int> res;
        for(auto x : words){
            res.push_back(t.search(x));
        }
        return res;
    }
};