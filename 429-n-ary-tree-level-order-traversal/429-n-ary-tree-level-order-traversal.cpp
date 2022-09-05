/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        vector<vector<int>> ans;
        if(!root) return {};
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> lev;
            
            for(int i = 0 ; i < sz ; i++){
                Node * top = q.front();
                lev.push_back(top->val);
                q.pop();
                for(auto x : top->children){
                    if(x) q.push(x);
                }
            }
            ans.push_back(lev);
        }
        return ans;
    }
};