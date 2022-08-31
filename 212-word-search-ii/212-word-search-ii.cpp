struct node{
    char ch;
    unordered_map<char,node*> m;
    bool isterminal;
    
    node(char _ch){
        ch = _ch;
        isterminal = false;
    }
};

struct trie{
    node * root;
    
    trie(){
        root = new node('\0');
    }
    
    void add_word(string word){
        node * temp = root;
        for(char ch : word){
            if(temp->m.count(ch) == 0){
                temp->m[ch] = new node(ch);
            }
            temp = temp->m[ch];
        }
        temp->isterminal = true;
    }
    
    bool search(string word){
        node * temp = root;
        for(char ch : word){
            if(temp->m.count(ch) == 0){
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isterminal == true;
    }
};
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


class Solution {
public:
    vector<string> found;
    void helper(vector<vector<char>>& board  , int i , int j , string &ans,node* temp,int m , int n){
        ans += board[i][j];
        if(temp->isterminal == true){
            temp->isterminal = false;
            found.push_back(ans);
            // return;
        }
        char ch = board[i][j];
        board[i][j]='0';
        
        for(int k = 0 ; k < 4 ; k++){
            
            int x = i+dx[k];
            int y = j+dy[k];
            
            if(x>=0 and x<m and y>=0 and y<n and board[x][y] != '0' and temp->m.count(board[x][y])){
                helper(board,x,y,ans,temp->m[board[x][y]],m,n);
            }
            
        }
        board[i][j] = ch;
        ans.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie tr;
        for(auto x : words){
            tr.add_word(x);
        }
        node * temp = tr.root;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                temp = tr.root;
                if(temp->m.count(board[i][j])==1){
                    string ans = "";
                    helper(board,i,j,ans,temp->m[board[i][j]],m,n);
                    // cout<<"\n";
                }
            }
        }
        return found;
    }
};