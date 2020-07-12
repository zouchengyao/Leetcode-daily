/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        auto curr = head;
        unordered_map<Node*, Node*> m; // this maps the alias of different node
        auto sentiel = new Node(0);
        auto prev = sentiel;
        while(curr != NULL)
        {
            // iterating all the nodes
            auto newNode = new Node(curr->val);
            if(curr!=NULL)  m[curr] = newNode;
            // m[newNode] = curr;
            newNode -> random = curr -> random;
            // linking
            prev -> next = newNode;
            prev = newNode;
            curr = curr -> next;
        }
        curr = sentiel->next;
        while( curr != NULL )
        {
            if (curr != NULL)
            curr -> random = m[curr->random];
            curr = curr -> next;
        } 


        return sentiel->next;

    }
};
// @lc code=end

