/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        auto currA = headA, currB = headB;
        while(currA != NULL && currB != NULL)
        {
            currA = currA -> next; currB = currB -> next;
        }
        if (currA == NULL)  currA = headB;
        if (currB == NULL)  currB = headA;

        while(currA != NULL && currB != NULL)
        {
            currA = currA -> next;
            currB = currB -> next;
        }
        
        if (currA == NULL)  currA = headB;
        if (currB == NULL)  currB = headA;
        while( currA != NULL && currB != NULL)
        {
            if (currA == currB) return currA;
            currA = currA -> next;
            currB = currB -> next;
        }
        return NULL;
    }
};
// @lc code=end

