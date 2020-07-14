/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        auto curr = l1;
        if (l1 == NULL)     return l2;
        if (l2 == NULL) return l1;

        while(curr != NULL)
        {
            s1.push(curr->val);
            curr = curr -> next;
        }
        curr = l2;
        while(curr!=NULL)
        {
            s2.push(curr->val);
            curr = curr -> next;
        }

        int carry = 0;
        long int sum = 0;
        auto sentiel = new ListNode(0);
        auto prev = sentiel;
        while( !s1.empty() && !s2.empty() )
        {
            // while both of these stacks are full
            int a = s1.top();
            int b = s2.top();
            s1.pop();
            s2.pop();
            int digit = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;

            auto newNode = new ListNode(digit);
            prev -> next = newNode;
            prev = newNode;
        }

        if (!s1.empty())
        {
            while(!s1.empty())
            {
                prev -> next = new ListNode( (s1.top() + carry) % 10 );
                prev = prev -> next;
                carry = (s1.top() + carry ) / 10;
                s1.pop();
            }
        }
        else
        {
            while(!s2.empty())
            {
                prev -> next = new ListNode( (s2.top() + carry) % 10 );
                prev = prev -> next;
                carry = (s2.top() + carry ) / 10;
                s2.pop();
            }
        }
        
        if (carry == 1)
            prev -> next = new ListNode(1);


        prev = NULL;
        curr = sentiel -> next;
        while( curr != NULL )
        {
            auto temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }


        return prev;
    }
};
// @lc code=end

