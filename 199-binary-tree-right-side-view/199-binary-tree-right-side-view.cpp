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
    
    void helper(TreeNode* root , vector<int> &ans , int level,int &last){
        if(root == NULL) return;
        if(level > last){
            ans.push_back(root->val);
            last = level;
        }
        helper(root->right,ans,level+1,last);
        helper(root->left,ans,level+1,last);
        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int last =0;
        helper(root,ans,1,last);
        return ans;
    }
};