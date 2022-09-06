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
    bool helper(TreeNode * root){
        if(!root) return false;
        
        bool left = helper(root->left);
        bool right = helper(root->right);
        
        
        if(!left) root->left = NULL;
        if(!right) root->right = NULL;
        if(!left and !right and root->val == 0) return false;
        
        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool check = helper(root);
        if(!check) return NULL;
        return root;
    }
};