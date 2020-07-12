/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)   return head;
        if (head -> next == NULL)  return head;
        auto sentiel = new ListNode(INT_MIN);
        sentiel -> next = head;
        auto n0 = sentiel, n1 = head, n2 = head->next;
        while(n2 != NULL)
        {
            // cout << n0->val << " ";
            // cout << n1->val << " "; 
            // cout << n2->val ; 
            // cout << "\n======" << endl;
            
            if (n1->val == n2->val)
            {
                // if the next two are the same
                // cout << "deleting" << endl;
                
                while( n2->val == n1->val )
                {
                    n2 = n2 -> next;
                    if (n2 == NULL) break;
                }
                n0 -> next = n2;
                n1 = n2;
                if (n2 != NULL) n2 = n2->next;
                
                continue;
            }

            // move on
            n0 = n1;
            n1 = n2;
            n2 = n2->next;
        }

        

        return sentiel->next;        

    }
};
// @lc code=end

