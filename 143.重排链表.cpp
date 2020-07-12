/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        auto mid = head, end = head;
        if (head == NULL)   return;
        while(end != NULL && end -> next != NULL)
        {
            mid = mid -> next;
            end = end -> next -> next;
        }
        
        ListNode * prev = NULL;
        auto curr = mid;
        while(curr != NULL)
        {
            auto temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        // cout << mid -> val << endl;
        // prev hold the last node addr
        // 
        auto sentiel = new ListNode(0);
        sentiel -> next = head;

        auto h_curr = head;        
        curr = prev;
        prev = sentiel; 
        while(curr != NULL)
        {
            // cout << "right list: " << curr -> val << endl;
            // cout << "left list: " << h_curr -> val << endl;
            if (h_curr == curr)
            {
                prev -> next = curr;
                curr -> next = NULL;
                break;
            } 
            auto temp = h_curr -> next;
            h_curr -> next = curr;
            prev -> next = h_curr;
            
            prev = curr;

            h_curr = temp;
            curr = curr -> next;
            prev -> next = NULL;       
        }        
    }
};
// @lc code=end

