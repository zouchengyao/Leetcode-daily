/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        int w = matrix[0].size();
        int h = matrix.size();


        for (int i = 0; i < w; i++)
        {
            int base = matrix[0][i];
            
            int x = i + 1, y = 1;
            while(x < w && y < h)
            {
                // cout << y << ":" << x << endl;
                // cout << "base is " << base << ", cell is " << matrix[y][x] << endl;
                if ( matrix[y][x] != base )
                    return false;
                x++;
                y++;
            }
        }

        for (int i = 0; i < h; i++)
        {
            int base = matrix[i][0];
            
            int x = 1, y = i+1;
            while(x < w && y < h)
            {
                // cout << y << ":" << x << endl;
                // cout << "base is " << base << ", cell is " << matrix[y][x] << endl;
                if ( matrix[y][x] != base )
                    return false;
                x++;
                y++;
            }
        }

        return true;
    }
};
// @lc code=end

