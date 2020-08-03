/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        // if (root == nullptr)    maxDiameter = 0;
        findDiameter(root, maxDiameter);
        return maxDiameter;
    }

    int findDiameter(TreeNode* root, int &maxDiameter)
    {
        // base case
        if (root == nullptr)    return 0;

        // for every node
        auto left = findDiameter(root->left, maxDiameter);
        auto right = findDiameter(root->right, maxDiameter);

        if (left + right > maxDiameter) maxDiameter = left + right;
        return max( left, right )+1;
    }

};
// @lc code=end

