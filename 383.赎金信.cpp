/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> v;

        for (auto c : magazine)
            v[c]++;
        
        for (auto c : ransomNote)
        {
            if (v.find(c) == v.end())   return false;
            if (v[c] == 0)  return false;
            else
                v[c] --;
        }                

        return true;
    }
};
// @lc code=end

