/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            
            int sz = q.size();
            if(q.front() == NULL) break;
            for(int i = 0 ; i < sz ; i++){
                auto top = q.front();
                q.pop();
                if(i+1==sz){
                    top->next = NULL;
                }else{
                    top->next = q.front();
                }
                q.push(top->left);
                q.push(top->right);
            }   
        }
        return root;
    }
};