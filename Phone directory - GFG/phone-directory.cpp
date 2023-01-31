//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct node{
        char d;
        map<char,node *> m;
        bool isterminal;
        
        node(char _d){
            d = _d;
            isterminal = false;
        }
    };
    
    struct trie{
        node * root;
        
        trie(){
            root = new node('\0');
        }
        
        void add(string s){
            node * temp = root;
            for(auto ch : s){
                if(temp->m.count(ch) == 0){
                    node * n = new node(ch);
                    temp->m[ch] = n;
                }
                temp = temp->m[ch];
            }
            temp->isterminal = true;
        }
        
        void recursive(node * temp , string res , vector<string> &ans){
            if(temp->isterminal == true){
                ans.push_back(res);
            }
            for(auto x : temp->m){
                char ch = x.first;
                node * next = x.second;
                res += ch;
                recursive(temp->m[ch],res,ans);
                res.pop_back();
            }
        }
        
        vector<vector<string>> search(string s){
            node * temp = root;
            vector<vector<string>> ans;
            string res = "";
            bool allfound = false;
            for(auto ch : s){
                res += ch;
                vector<string> check;
                if(temp->m.count(ch) == 0 or allfound){
                    allfound = true;
                    ans.push_back({"0"});
                    continue;
                }
                temp = temp->m[ch];
                recursive(temp,res,check);
                ans.push_back(check);
                
            }
            return ans;
        }
    };
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie t;
        for(int i = 0 ; i < n ; i++){
            t.add(contact[i]);
        }
        
        return t.search(s);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends