/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return findInS(s, t); 
    }

    bool findInS(TreeNode* s, TreeNode* t)
    {
        if ( s == nullptr )     return false;
        if (s->val == t->val)
        {
            cout << "s->val match found: ";
            if (findInT(s, t))  
            {
                cout << "matching!" << endl;
                return true;
            }
            else
            {
                cout << "not matching." << endl;
            }
            
        }
        return findInS(s->left, t) || findInS(s->right, t);
    }

    bool findInT(TreeNode* s, TreeNode* t)
    {
        if ( s == nullptr && t == nullptr ) return true;
        else if ( s == nullptr || t == nullptr)  return false;
        if ( s->val != t->val)  return false;
        return findInT(s->left, t->left) && findInT(s->right, t->right);
    }
};
// @lc code=end

