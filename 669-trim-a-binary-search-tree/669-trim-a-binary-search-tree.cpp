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
    TreeNode* helper(TreeNode * root , int &low , int &high){
        if(root == NULL) return NULL;
        
        auto left = helper(root->left,low,high);
        auto right = helper(root->right,low,high);
        root->left = left;
        root->right = right;
        if(root->val<low){
            return root->right;
        }else if(root->val>high){
            return root->left;
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = helper(root,low,high);
        return root;
    }
};