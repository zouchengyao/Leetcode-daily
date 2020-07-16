/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
        unordered_map<TreeNode*, int> s;
        unordered_map<TreeNode*, vector<int> > m;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root != nullptr) m[root] = {root->val};
        // this time I'll try to write it recursively. 
        vector<vector<int>> v;
        helper(root, sum, v);
        return v;

    }

    void helper( TreeNode* root, int sum, vector<vector<int>> &v ) 
    {
        if (root == nullptr)    return;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == root->val)
            {
                // auto temp = m[root];
                // m[root].push_back(root->val);
                v.push_back(m[root]);
            }
        }
        // helping with its kids
        if (root->left != nullptr)
        {
            m[root->left] = m[root];
            m[root->left].push_back(root->left->val);
        }  
        if (root->right != nullptr)
        {
            m[root->right] = m[root];
            m[root->right].push_back(root->right->val);
        }

        helper(root->left, sum - root->val, v);
        helper(root->right, sum - root->val, v);

    }   




    vector<vector<int>> pathSumV1(TreeNode* root, int sum) {
    queue<TreeNode*> q;
    if (root == nullptr)    return {};
    // BFS Search here; we will use a prev mapping for backtracking
    q.push(root);
    vector<vector<int>> res;
    unordered_map<TreeNode*, int> prevSum;
    unordered_map<TreeNode*, TreeNode*> prevNode;
    vector<TreeNode*> valid;
    prevSum[root] = 0;

    while( !q.empty() )
    {
        auto curr = q.front();      q.pop();
        // cout << curr -> val << endl;
        if (curr -> left == nullptr && curr -> right == nullptr )
        {
            // cout << "Find leaf: " << curr -> val << ", sum is " << prevSum[curr] << endl;
            if (prevSum[curr] + curr->val == sum)
                valid.push_back(curr);
        }

        if ( curr->left != nullptr ) 
        {
            prevSum[curr->left] = curr->val + prevSum[curr] ;  
            q.push(curr->left);
            prevNode[curr->left] = curr; 
        }
        if ( curr->right != nullptr )
        {
            prevSum[curr->right] = curr->val + prevSum[curr];
            q.push(curr->right);
            prevNode[curr->right] = curr;
        }
    }   

    for( const auto & leaf : valid)
    {
        // cout << "leaf: " << leaf -> val << endl;
        vector<int> temp;
        auto curr = leaf;
        while(curr != root)
        {
            temp.push_back(curr->val);
            curr = prevNode[curr];
        }
        temp.push_back(root->val);
        reverse(temp.begin(), temp.end());
        res.push_back(temp);        
    }

    return res;
    }
};
// @lc code=end

