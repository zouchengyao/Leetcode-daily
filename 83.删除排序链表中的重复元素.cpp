/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
       if (head == NULL) return head;
       if (head -> next == NULL) return head;
       ListNode * curr = head, * next = head -> next;

       while(next != NULL)
       {
           if (curr -> val == next -> val)
            {
                curr -> next = next -> next;
                next = next -> next;
                continue;
            }

           curr = next;
           next = next -> next;
       }
       return head; 
    }
};
// @lc code=end

