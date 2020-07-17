/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int sumNumbers(TreeNode* root) {

        // if (root == nullptr ) return 0;
        // if (root -> left == nullptr && root -> right == nullptr)
        // {
        //     // if you are the leaf node
        //     return root->val; 
        // }


        // auto leftSum = sumNumbers(root->left);

        // auto rightSum= sumNumbers(root->right);

        // return leftSum + rightSum + 20 * root->val;
        return recursion(root, 0);
        // int sum = 0;
        // for (const auto & c : v)
            // sum += c;
        // return sum;

    }

    int recursion(TreeNode* root, long int sum)
    {
        if (root == nullptr)    return 0;
        int rootSum = sum * 10 + root -> val;
        if (root -> left == nullptr && root -> right == nullptr)
        {
            // if this is the leaf node
            return sum * 10 + root->val;
        }

        return recursion(root->left, sum*10 + root->val ) + recursion(root->right, sum*10 + root -> val);
    }
};
// @lc code=end

