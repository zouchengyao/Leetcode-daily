/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)   return head;
        int distance = n - m + 1;
        auto sentiel = new ListNode(-10);
        sentiel -> next = head;
        auto start = sentiel, end = head;
        
        while(distance--)
        {
            end = end -> next;       
        }        
        int shift = m - 1;
        while(shift--)
        {
            end = end -> next;
            start = start -> next;
        }
        // if (end != NULL)
            // cout << "start is " << start->val << ", and end is " << end->val << endl;          
        reverse(start, end);
        return sentiel->next;
    }

    ListNode* reverse(ListNode* start, ListNode* end)
    {
        //
        if (start == end)   return start;

        auto curr = start -> next;
        auto prev = start;

        while(curr != end)
        {
            auto temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        start -> next -> next = end;
        start -> next = prev;        

        return end;

    }

};
// @lc code=end

