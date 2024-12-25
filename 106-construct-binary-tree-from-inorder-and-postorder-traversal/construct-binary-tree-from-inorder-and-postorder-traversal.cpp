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
    TreeNode* buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int posStart, int posEnd, map<int, int> &inMap){
        if(inStart > inEnd || posStart > posEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[posEnd]);
        int rootIdx = inMap[postorder[posEnd]];
        int numsLeft = rootIdx - inStart;
        root->left = buildTree(inorder, inStart, rootIdx-1, postorder, posStart, posStart+numsLeft-1, inMap);
        root->right = buildTree(inorder, rootIdx+1, inEnd, postorder, posStart+numsLeft, posEnd-1, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }
};