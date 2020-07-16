/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* connect(Node* root)
    {
        //we will use the recursion here
        if (root == nullptr)    return nullptr;

        // if left exists, right must exists; the parent node guide the left's next to point to right node
        if (root -> left != nullptr)
            root -> left -> next = root -> right;

        // if right exists, right child should point to the root->next->left.
        if (root->next != nullptr && root -> right != nullptr)
        {
            // if the parent has the next on the right, which the right child will be connected with its left child
            root -> right -> next = root -> next -> left;
        }
        connect(root->left);
        connect(root->right);
        return root;

    }

    queue<Node*> v;
    Node* connectV2(Node* root) {
        // using BFS for level-order traversal
        if (root == nullptr)    return {};
        queue<Node*> q;
        int count = 0;
        int level = 1;
        q.push(root);
        auto prev = root;
        while(!q.empty())
        {
            auto curr = q.front();  q.pop();
            // cout << curr -> val << ":" << count <<"<" << level<< endl;
            if ( count > 0 &&  count < level )
            {
                
                // cout << "linking: " << prev->val << " to " << curr->val << endl;
                prev -> next = curr;
                // count++;
            }
            else if (count >= level)
            {
                // reset for next level
                level *= 2;
                count = 0;
            }

            // moving to next
            count++;
            prev = curr;
            if(curr->left != nullptr)   q.push( curr->left );
            if(curr->right!= nullptr)   q.push( curr->right);
        }
        
    return root;


    }

    void r(Node* root)
    {
        if (root == nullptr)
            return;
        v.push(root);
        r(root->left);
        r(root->right);
    }

};
// @lc code=end

