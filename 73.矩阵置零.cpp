/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int w = matrix[0].size();
        int h = matrix.size();
        bool firstRow = false, firstCol = false;
       for ( int i = 0; i < h; i++ )
       {
           for (int j = 0; j < w; j++)
           {
               if ( matrix[i][j] == 0 )
               {

                   if (i == 0) firstRow = true;
                   if (j == 0) firstCol = true;
                   // then we overwrite its corresponding col / row
                // we can indexing what we want to change
                matrix[0][j] = 0;
                matrix[i][0] = 0;
               }
           }
       }
        // now, the first row and first col are used as indexing for the remaining
        // we will leave it temporarily for good usage
        for (int i = 1; i < h; i++)
        {
            for (int j = 1; j < w; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (firstCol)
        {
            for( int i = 0; i < h; i++)
                matrix[i][0] = 0;
        }
        if (firstRow)   
        {
            for (int i = 0; i < w; i++)
                matrix[0][i] = 0;
        }
    }
};
// @lc code=end

