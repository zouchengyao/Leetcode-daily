/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        auto mid = head, end=  head;
        if (head == NULL)   return true;
        if (head -> next == NULL)   return true;

        while(end != NULL && end -> next != NULL)
        {
            mid = mid -> next;
            end = end -> next -> next;
        }
        // now mid is the mid point, which should have two cases
        auto prev = head;
        if (end == NULL) {
          // there are even number of nodes
          // mid is the start of the flipped list
          auto newhead = mid;
          auto curr = mid;
          prev = NULL;
          while (curr != NULL) {
            // flipping the next series
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
          }
        } else {
          // there are the odd number of nodes
          // mid is the center of the list
          auto curr = mid->next;
          prev = NULL;
          while (curr != NULL) {
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
          }
        }
        auto iter = head;
        // printL(head);
        // printL(prev);
        while(prev != NULL)
        {
            if (iter->val != prev->val)
                return false;
            iter = iter->next;
            prev = prev ->next;
        }

        return true;
    }

};
// @lc code=end

