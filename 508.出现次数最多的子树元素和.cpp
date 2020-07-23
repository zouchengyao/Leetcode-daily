/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        sum(root, m);
        int maxval = INT_MIN;        
        vector<int> res;
        for (const auto & p: m)
        {
            if (p.second == maxval)
            {
                // append one more element
                res.push_back(p.first);
            }
            if (p.second > maxval)
            {
                // update new maxval
                res.clear();
                res.push_back(p.first);
                maxval = p.second;
            }
        }
    return res;
    }

    int sum(TreeNode* root, unordered_map<int, int> &m)
    {
        if (root == nullptr)    return 0;

        int curr_sum = root -> val +sum(root->left, m) + sum(root->right, m);
        m[curr_sum]++;
        return curr_sum ; 
    }
};
// @lc code=end

