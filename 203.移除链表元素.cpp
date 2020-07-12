/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)   return head;
        auto sentiel = new ListNode(INT_MIN);
        sentiel ->next = head;
        auto prev = sentiel, curr = head;
        while(curr != NULL)
        {
            if (val == curr -> val)
                prev -> next = curr -> next;
            
            else
            prev = curr;
            curr = curr -> next;
        }

        return sentiel -> next;
    }
};
// @lc code=end

