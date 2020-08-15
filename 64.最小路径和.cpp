/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    struct pair
    {
        int y;
        int x;
        pair(int y, int x) : y(y), x(x) {}
    };

    int minPathSum(vector<vector<int>> &grid)
    {
        // or , i can do a bfs search here
        int w = grid[0].size();
        int h = grid.size();
        queue<pair> q;
        q.push(pair(0,0));

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.x;
            int y = p.y;


            // push two next elements
            q.push


        }

        return 0;
    }

    


    int minPathSum1(vector<vector<int>>& grid) {
       // a simple dp problem
       int w = grid[0].size();
       int h = grid.size();
        vector<vector<int>> dp ( h, vector<int>(w, 0) );
        int prev = 0;
        for (int i = 0; i < w; i++)
        {
            dp[0][i] = prev + grid[0][i];
            prev = dp[0][i];
        }
        prev = 0;
        for (int i = 0; i < h; i++)
        {
            dp[i][0] = prev + grid[i][0];
            prev = dp[i][0];
        }

        for (int i = 1; i < w; i++)
        {
            for (int j = 1; j < h; j++)
            {
                dp[j][i] = min( dp[j-1][i] , dp[j][i-1] ) + grid[j][i];
            }
        }
        // for (auto c : grid)
        // {
        //     for (auto a : c)
        //         printf("%d ", a );
        //     printf("\n");
        // }

        // cout << "=============" << endl;
        // for (auto c : dp)
        // {
        //     for (auto a : c)
        //         printf("%d ", a );
        //     printf("\n");
        // }

        return dp[h-1][w-1];
    }
};
// @lc code=end

