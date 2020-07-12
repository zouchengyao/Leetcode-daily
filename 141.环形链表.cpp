/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return head;
       auto fast = head -> next, slow = head;
        while(fast != NULL)
        {
            if (fast == slow)   return true;
            else
            {
                if (fast -> next == NULL) return false;
                fast = fast -> next -> next;
                slow = slow -> next;
            }
        }

        return false; 
    }
};
// @lc code=end

