#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
    int target;
public:
    void DFS(int index,  int sum) {
        if (target == sum) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size() &&  candidates[i] + sum <= target ; i++) 
        {
            path.push_back(candidates[i]);
            DFS(i, sum + candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->target = target;
        DFS(0, 0);

        return res;
    }

};

