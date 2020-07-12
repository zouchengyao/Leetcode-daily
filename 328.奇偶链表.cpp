/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        
        auto odd = head, even = head -> next;
        auto odd_sentiel = new ListNode();
        auto even_sentiel = new ListNode();
        auto odd_prev = odd_sentiel, even_prev = even_sentiel;

        while(odd != NULL || even != NULL )
        {
            // both of them should be valid nodes
                odd_prev -> next = odd;
                odd_prev = odd;

                if (even != NULL) odd = even -> next;
                else odd = NULL;

            if (even != NULL)
            {
                even_prev -> next = even;
                even_prev = even;
                if (even -> next != NULL)   even = even -> next -> next;
                else even = NULL;

            }
        }
            // concatenate two lists 
            even_prev -> next = NULL;
            odd_prev -> next = even_sentiel -> next;

        return odd_sentiel -> next;
    }
};
// @lc code=end

