/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
    auto smaller = new ListNode(0);
    auto greater = new ListNode(0);
    
    auto curr = head, s = smaller, g = greater;
    while( curr != NULL)
    {
        // cout << "asd" << endl;
        if (curr -> val < x)
        {
            // should append it to the smaller linkedlist
            s->next = curr;        
            s = s->next;
        }    
        else
        {
            // should append it to the greater list
            g->next = curr;
            g = g -> next;
        }
        auto temp = curr -> next;
        

        curr = temp;   
    }
    s->next = greater->next;
    g->next = NULL;
     return smaller->next;   


    }
};
// @lc code=end

