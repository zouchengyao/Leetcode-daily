/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
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
    vector<TreeNode*> generateTrees(int n) {

        if (n == 0) return {};

        return r(1, n);        

    }

    // if asks you to build something, then using recursion is a good way

    vector<TreeNode*> r(int start, int end)
    {
        if (start > end)    return {nullptr};
        vector<TreeNode*> res;
        for ( int i = start; i <= end; i++ )
        {
            auto left = r(start, i-1);
            auto right = r(i+1, end);
            for (auto a : left)
            {
                for (auto b : right)
                {
                    cout << "ONE TIME" << endl;
                    auto node = new TreeNode(i);
                    node -> left = a;
                    node -> right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }



};
// @lc code=end

