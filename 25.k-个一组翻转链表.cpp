/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        auto sentiel = new ListNode(0);
        sentiel -> next = head;
        ListNode * curr = sentiel;
        if (k == 1) return head;
        while(curr != NULL)
        {
            count++;   
            curr = curr -> next;
        }
        
        ListNode * start = sentiel, *end = head;
        int c = k;
        
        while(1)
        {
            c = k;
            if(end == NULL) break;
            while(c--)
            {
                end = end -> next; 
                if ( end == NULL)   break;
            }
        // calculated the end
            if (c > 0 && end == NULL)
                break;
            else
            {
                // cout << "Start safe node is" << start->val << endl;
            // if (end != NULL)    cout << "End safe node is " << end-> val << endl;
            // else                cout << "end is a null ptr" << endl;
                start = reverseK(start, end);
                // printL(sentiel->next);
            }
        }

        return sentiel->next;        
    }

    void printL(ListNode* head)
    {
        printf(">>> ");
        while(head != NULL)
        {
            printf("%d->", head -> val );
            head = head -> next;

        }
        printf("NULL\n");
    }

    ListNode* reverseK(ListNode* head, ListNode* tail)
    {
        // these should be valid parameters
        // we are not touching head and tail, we just connect with them
        ListNode * curr = head->next, * prev = tail;
        ListNode * ret = head->next;
        while(curr != tail)
        {            
            auto temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        head -> next = prev;
        return ret;
    }


};
// @lc code=end

