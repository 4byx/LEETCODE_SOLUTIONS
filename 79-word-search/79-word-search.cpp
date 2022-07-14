int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
class Solution {
public:
    bool valid(int x , int y , int m , int n){
        return (x<m and x>=0 and y<n and y>=0);
    }
    bool check(string & word , vector<vector<char>>& board , int  x , int y ,int i, int m , int n,vector<vector<int>> &vis){
        
        if(i==word.size()-1 and board[x][y]==word[i]) return true;
        vis[x][y] = 1;
        
        for(int k = 0 ; k < 4 ; k++){
            int xx = x+dx[k];
            int yy = y+dy[k];
            
            if(valid(xx,yy,m,n) and board[x][y] == word[i] and !vis[xx][yy] and check(word,board,xx,yy,i+1,m,n,vis)) return true;
        }
        
        vis[x][y] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j <n ; j++){
                if(board[i][j]==word[0]){
                    if(check(word,board,i,j,0,m,n,vis)) return true;
                }
            }
        }
        return false;
    }
};