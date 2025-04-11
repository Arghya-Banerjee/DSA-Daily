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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> s1;
        vector<int> ans;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* temp = s1.top();
            s1.pop();
            if(temp->left) s1.push(temp->left);
            if(temp->right) s1.push(temp->right);
            ans.push_back(temp->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};