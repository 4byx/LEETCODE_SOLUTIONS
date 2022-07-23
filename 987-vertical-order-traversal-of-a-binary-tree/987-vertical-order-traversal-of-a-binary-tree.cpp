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
    
    void helper(TreeNode *root , int x  , int y , map<int,map<int,vector<int>>> &m){
        if(!root){
            return;
        }
        
        m[x][y].push_back(root->val);
        
        helper(root->left,x-1,y+1,m);
        helper(root->right,x+1,y+1,m);
        
        return;
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        helper(root,0,0,m);
        
        vector<vector<int>> ans;
        
        for(auto x : m){
            vector<int> v;
            for(auto y : x.second){
                sort(y.second.begin(),y.second.end());
                
                for(auto i : y.second){
                    v.push_back(i);
                }
                
            }
            ans.push_back(v);
        }
        
        return ans;
        
    }
};













