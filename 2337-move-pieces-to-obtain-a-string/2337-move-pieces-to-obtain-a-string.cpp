class Solution {
public:
    bool canChange(string start, string target) {
        
        int i=0,j=0,n = start.size();
        while(i<n and j<n){
            
            while(i<n and start[i]=='_')i++;
            while(j<n and target[j]=='_')j++;
            
            if(i==n and j==n){ cout<<"1"; return true;}
            else if(i==n or j==n){cout<<"2"; break;}
            if(start[i]!=target[j]){cout<<"3"; return false;}
            if(start[i]=='R'){
                if(i>j) return false;
            }else if(start[i]=='L'){
                if(j>i) return false;
            }
            i++;
            j++;
            
        }
        while(i<n and start[i]=='_')i++;
        while(j<n and target[j]=='_')j++;
        
        if(i!=n or j!=n) { cout<<"4"; return false;}
               
        return true;
    }
};