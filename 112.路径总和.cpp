/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        // if (root == nullptr)    return false;
        // return pathsumv2(root, sum);        

        if (root == nullptr)    return false;
        queue<TreeNode*> nodeq;
        queue<int> sumq;

        nodeq.push(root);
        sumq.push(0);
        while(nodeq.size() != 0)
        {
            auto curr = nodeq.front();      nodeq.pop();
            auto currsum = sumq.front();    sumq.pop(); 
            // cout << curr -> val << endl;
                // cout << "Node: " << curr->val << ", sum is " << currsum << endl;
            // if this is the leaf node
            if (curr -> left == nullptr && curr -> right == nullptr)
            {
                if ((currsum + curr->val) == sum) return true;
            }

            if (curr-> left != nullptr )
            {
                nodeq.push(curr->left);
                sumq.push(curr->val + currsum);
            }
            if (curr->right != nullptr )    
            {
                nodeq.push(curr->right);
                sumq.push(curr->val + currsum);
            }
        }
        return false;
    }


















    bool pathsumv2(TreeNode* root, int sum)
    {
        if (root == nullptr)    return false;
        if (root -> left == nullptr && root -> right == nullptr)    return root->val == sum;

        return ( pathsumv2(root->left, sum - root->val) || pathsumv2(root->right, sum - root->val) );

    }



    bool pathsum(TreeNode* root, int s, int k)
    {
        // 
        if (root -> left == nullptr && root->right == nullptr)
        {
            // if this is the leaf node
            if ( (s + root->val) == k) return true; 
            else return false;
        }
        bool ls = false, rs = false;
        if (root->left != nullptr)  ls = pathsum(root->left, s+root->val, k);
        if (root->right != nullptr) rs = pathsum(root->right, s+root->val, k);
        return ls || rs;
    }

};
// @lc code=end

