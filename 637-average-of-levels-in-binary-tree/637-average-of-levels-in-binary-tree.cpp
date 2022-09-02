/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        
        vector<double> ans;
        q.push(root);
        long res;
        while(!q.empty()){
            
            int sz = q.size();
            
            res = 0;
            
            for(int i = 0 ; i < sz ; i++){
                auto top = q.front();
                q.pop();
                res += top->val;
                
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            double c = res/(double)sz;
            ans.push_back(c);
        }
        return ans;
    }
};