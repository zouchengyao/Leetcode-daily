/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int k;
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*> s;
        auto curr = root;
        while(1)
        {
            while(curr != nullptr)
            {
                s.push(curr);
                curr = curr -> left;
            }   // find the leaf node all the way down

            curr = s.top(); s.pop();
            // cout << "Node  " << curr -> val << endl; 
            k-=1;
            if (k == 0) return curr->val;
            // this part is IMPORTANT:
            // if still not found enough, we need to traverse to the right node, which is definitely smaller than root's parent. We can still find hopeful result under such content. 
            curr = curr -> right;       // this leaf node has been overused; try its right node
        }
    }




    int kthSmallestv2(TreeNode* root, int k) {
        // basically, an pre-order traversal
        vector<int> res;
        this -> k = k;
        r(root, res);
        return res.back();

    }

    void r( TreeNode* root, vector<int> &res )
    {
        if (root == nullptr)    return;

        r(root->left, res);
        if (res.size() == k ) return;
        res.push_back(root->val);
        if (res.size() == k ) return;
        r(root->right, res);

    }


};
// @lc code=end

