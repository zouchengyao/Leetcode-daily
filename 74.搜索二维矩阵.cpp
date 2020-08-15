/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)  return false;
        int h = matrix.size();
        int w = matrix[0].size();

        int col = searchCol(0, h-1, matrix, target);
        cout << "It is row " << col << endl;

        auto & row = matrix[col];

        
        return searchRow(row, target);

        // now i is the 
        // auto it = find(row.begin(), row.end(), target);
        // if (it != row.end())    return true;
        // return false;



    }

    int searchCol( int left, int right, vector<vector<int>> & matrix, int target)
    {
        while(left < right)
        {
            auto mid = left + 1 + (right - left) / 2;

            if ( matrix[mid][0] <= target )
                left  = mid;
            else 
                right = mid - 1;
        }
        
        return left;    // either left or right is a good return
    }

    bool searchRow(vector<int> row, int target)
    {
        int left = 0, right = row.size()-1;
        if (right < 0)   return false;
        // if (right == left)  return row[left] == target;

        while(left <= right)
        {
            auto mid = left + (right - left) / 2;
            if ( row[mid] == target )
                return true;
            else if ( row[mid] > target)
                right = mid -1;
            else
                left = mid + 1;
        }

        return false;
    }


};
// @lc code=end

