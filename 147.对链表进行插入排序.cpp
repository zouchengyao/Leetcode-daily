/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL )  return head;
        ListNode* sentiel = new ListNode(0);

        ListNode* curr = head;
        while( curr != NULL)
        {
            ListNode* temp = curr -> next;
            insert(sentiel, curr);
            // cout << "Inserting " << curr -> val << endl;
            curr = temp;
        }

        return sentiel -> next;

    }

    void insert(ListNode* sentiel, ListNode * node)
    {
        // we will traverse the res list to insert the node in the proper position
        ListNode* curr = sentiel -> next;
        ListNode* prev = sentiel;
        while(curr != NULL )
        {
            if ( node->val < curr->val )
            {
                // insert behind the prev node
                prev -> next = node;
                node -> next = curr;    // inserted
                return;
            }
            prev = curr;
            curr = curr -> next;

        }
        // else, append this node cause its the largest
        prev -> next = node;
        node -> next = NULL;
    }

};
// @lc code=end

