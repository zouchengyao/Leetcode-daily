/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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

    string tree2str(TreeNode* t) {
        // string s;
        // recursion(t, s);
        // if(s.size() < 2)    return s;
        // s.pop_back();
        // s.erase(s.begin());
        // return s;
        string s;
        R(t, s);
        return s;

    }

    void R(TreeNode* t, string &s)
    {
        if ( t == nullptr ) return;
        // pre-order traversal
        s += to_string(t->val);
        if (t -> left || t -> right)
        {
            s += '(';
            R(t->left, s);
            s += ')';
        }
        if (t -> right)
        {
            s += '(';
            R(t->right, s);
            s += ')';
        }
        
    }


    void recursion(TreeNode* t, string &s)
    {
        if ( t == nullptr )
            return;
        
        s = s +  '('+ to_string( t->val);
        if ( t -> left == nullptr && t->right != nullptr)    s += "()";
        recursion(t->left, s);
        recursion(t->right, s);
        s += ')';
        return;
    }

};
// @lc code=end

