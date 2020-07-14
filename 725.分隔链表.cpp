/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {

       int count = 0;
       auto curr = root;
       while(curr != nullptr)
       {
           count++;
           curr = curr -> next;
       } 
        // count = 11;
        vector<int> v;
        int remain = count % k;
        int iter =k;
        while(  iter-- )
        {
            if (remain > 0)
                v.push_back((count / k) + 1);
            else
                v.push_back(count / k);
            remain--;
        }    

        // for (const auto & c : v)
            // cout << c << endl;
        vector<ListNode*> res;
        // cout << "---"<< endl;
        curr = root;
        while( !v.empty() )
        {
            int i = v.front();
            // cout << i << endl;
            v.erase(v.begin());
            if (i == 0)
            {
                res.push_back(NULL);            
                continue;
            }
            else i--;
            res.push_back(curr);
            while(i--)
            {
                curr = curr -> next;
            }
            auto temp = curr -> next;
            curr -> next = NULL;
            curr = temp;             

        }


  

        return res;
    }
};
// @lc code=end

