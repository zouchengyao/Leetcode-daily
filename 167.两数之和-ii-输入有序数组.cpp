/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        // set<int> s;
        int count = 1;
        for (const auto & n : numbers)
        {
            if ( m.find(n) != m.end() )
                return {m[n], count};
            // else, insert it
            // s.insert(target - n);
            m[target - n] = count;
            count ++;
        }
        return {};
    }
};
// @lc code=end

