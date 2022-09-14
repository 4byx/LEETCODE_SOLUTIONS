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
    int ans;
    bool check(map<int,int> &m){
        int cnt = 0;
        for(auto x :m){
            // cout<<x.first<<" ";
            if(x.second%2 == 1){
                if(cnt >= 1){
                    // cout<<"break \n";
                    return false;
                }
                cnt++;
            }
        }
        // cout<<"cnt \n";
        
        return cnt<=1;
    }
    void helper(TreeNode  *root , map<int,int> &m){
        if(!root) return;
        if(!root->left and !root->right){
            m[root->val]++;
            if(check(m)) ans++;
             m[root->val]--;
            if(m[root->val] == 0) m.erase(root->val);
            return;
        }
        
        m[root->val]++;
        helper(root->left,m);
        helper(root->right,m);
        m[root->val]--;
        if(m[root->val] == 0) m.erase(root->val);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        map<int,int> m;
        helper(root,m);
        return ans;
    }
};