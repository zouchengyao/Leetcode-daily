/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*> q, prev;
        q.push(root);
        int level = 1;
        if (d == 1) //TODO:
        {
            auto temp = new TreeNode(v);
            temp->left = root;
            return temp;
        }

        while(!q.empty())
        {
            prev = q;
            auto size = q.size();
            if (level == d - 1)
            {
                while(size--)
                {
                    auto curr = q.front();
                    q.pop();
                    auto l = curr ->left;
                    auto r = curr ->right;

                    curr -> left = new TreeNode(v);
                    curr -> right= new TreeNode(v);
                    if (l)
                    {
                        q.push(l);
                        curr->left->left=l;
                    }
                    if (r)
                    {
                        q.push(r);
                        curr->right->right = r;
                    }
                }
            }

            else
            {
                  while(size--)
                {
                    auto curr = q.front();
                    q.pop();
                    if (curr -> left) q.push(curr->left);
                    if (curr ->right) q.push(curr->right);
                }              /* code */
            }
            

            level++;
        }

        if (level == d) 
        while(!prev.empty())
        {
            auto node = prev.front();
            node -> left = new TreeNode(v);
            node -> right = new TreeNode(v);
            prev.pop();
        }

        return root;
    }
};
// @lc code=end

