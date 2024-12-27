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
private:
    int f(TreeNode* root){
        if(!root) return 0;
        int l = 0;
        int r = 0;
        if(root->left) l = f(root->left);
        if(root->right) r = f(root->right);
        return 1 + max(l, r);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return f(root);
    }
};