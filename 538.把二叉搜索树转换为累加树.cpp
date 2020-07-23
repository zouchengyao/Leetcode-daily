/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum;
    TreeNode* convertBST(TreeNode* root) {
    // method 1: inorder traversal (reversed to get the largest first)
        // sum = 0;
        // inorder(root);
        // return root;

    // method 2: stack DFS
        stack<TreeNode*> s;
         

    }
    void inorder(TreeNode* root)
    {
         if ( root == nullptr )  return;        

        inorder( root -> right);
        root -> val += sum;
        sum = root -> val;
        inorder(root->left);
        // return root -> val;
    }


    int addTree(TreeNode* root)
    {
        if (root == nullptr)    return 0;

        auto l = addTree(root->left);
        auto r = addTree(root->right);
        root -> val = root->val + r;
        return root -> val + l;
        


    }


};
// @lc code=end

