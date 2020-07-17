/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    vector<int> v;
    int iter;
    BSTIterator(TreeNode* root) {
        iter = 0;
        r(root);        
    }

    void r(TreeNode* root)
    {
        if (root == nullptr)    return;
        r(root->left);
        v.push_back(root->val);
        r(root->right);
        return;
    }


    
    /** @return the next smallest number */
    int next() {
        if (iter> v.size()-1)   return INT_MIN;
        iter++;
        return v.at(iter-1);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        // if (v.size() == 0)  return false;
        if ( iter+1 <= v.size() )   return true;    // iter is the next node's location
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

