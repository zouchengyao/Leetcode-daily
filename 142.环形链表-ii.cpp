/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
    //    struct junct
    //    {
    //        ListNode* node; 
    //        int pos;
    //      junct(ListNode* node, int pos): node(node), pos(pos) {}
    //    };
    if (head == NULL)   return head;
    auto slow = head, fast = head;

    while( fast )
    {
        fast = fast -> next;
        slow = slow -> next;
        if (fast != NULL)   fast = fast -> next;
        else    return NULL;

        if (slow == fast)
        {
            // 
            slow = head;
            while(fast != slow)
            {
                fast = fast -> next;
                slow = slow -> next;
            }
            return fast;
        }

    }
        return NULL;
    }
};
// @lc code=end

