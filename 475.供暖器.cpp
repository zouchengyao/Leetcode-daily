/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int res = INT_MIN;
        int i = 0;
        int left_dist = INT_MAX, right_dist = INT_MAX;

        for ( const auto & house : houses )
        {
            // we need to see each house's nearest heaters
            // we always pick the first right heater of each house, 
            // thus the left heater will be [right-1]
            while(1)
            {
                if (i == heaters.size()-1 )    break;  //safeguard

                if(heaters[i] > house )     break;
                else
                    i++;
            }
            // i is the index for the nearest right heater
            // cout << "------" << endl;
            if ( i-1 >= 0)    
                left_dist = abs( house - heaters[i-1] );
            else
                left_dist = INT_MAX;

            right_dist = abs( house - heaters[i] );

            res = max( res, min(left_dist, right_dist) );
        }


        return res;
    }
};
// @lc code=end

