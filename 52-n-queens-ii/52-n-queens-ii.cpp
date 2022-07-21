class Solution {
public:
    int N;
    int ans;
    
    int leftdiag[18] , col[9] , rightdiag[18];
    void search(int y) {
        
        if(y==N){
            ans++;
            return;
        }
        
        for(int x = 0 ; x < N ; x++){
            if(col[x] || leftdiag[x+y] || rightdiag[x-y+N-1]) continue;
            col[x] = leftdiag[x+y]  =rightdiag[x-y+N-1] = 1;
            search(y+1);
            col[x] = leftdiag[x+y]  =rightdiag[x-y+N-1] = 0;   
        }
    }

    int totalNQueens(int N) {
        this->N = N;
        ans = 0;
        search(0);
        return ans;
    }
};