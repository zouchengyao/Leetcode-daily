/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
    unordered_map<int, vector<Node*>> m;

    Node* connect(Node* root) {
        // bfs is your loyal friend
        if (root == nullptr)    return root;
        queue<Node*> q;
        
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            auto size = q.size();
            while(size--)
            {
                auto curr = q.front();      q.pop();
                m[level].push_back(curr);
                if (curr ->left != nullptr) q.push(curr->left);
                if (curr ->right!= nullptr) q.push(curr->right);
            }
            level++;
        }
        // every node should be stored at level-order 
        for (int i = 1; i <level; i++)
        {
            // traverse the map
            auto prev = m[i].front();
            for(auto & n : m[i])
            {
                if (n != m[i].front()  )
                {
                    prev -> next = n;
                    prev = n;
                }
            }

        }
        return root;
        
    }

    ///  MY RECURSION IS CORRECT!!! PARTIALLY....
    // because you need to traverse into the right child first to establish all next connection!!!
    /*
    simple fix:
        ... ... // everything above are the same
                // except below:::
        connection(root->right);
        connection(root->left);
    */


    Node* neighbor(Node* next)
    {
    
        if (next == nullptr)    return nullptr;
        // else    cout <<"finding in " << next -> val << endl;
        if (next->left != nullptr)  return next -> left;
        else if (next -> right != nullptr)  return next -> right;
        else if (next -> left == nullptr && next -> right == nullptr)
            return neighbor(next->next);
        else    return nullptr;
    }
    Node* neighborp(Node* next)
    {
    
        if (next == nullptr)    return nullptr;
        else    cout <<"finding in " << next -> val << endl;
        if (next -> left == nullptr && next -> right == nullptr)
            return neighborp(next->next);
        if (next->left != nullptr)  return next -> left;
        else if (next -> right != nullptr)  return next -> right;
        else    return nullptr;
    }


    void re(Node* r)
    {
        if (r == nullptr)   return;
        re(r->left);
        cout << r->val << endl;
        // if (r->next != nullptr)
        // cout << "Node: " << r->val << ", next is " << r->next->val << endl;
        // else
        // {
            // cout << "Node: " << r->val << endl;
        // }
        
        re(r->right);

    }

};
// @lc code=end

