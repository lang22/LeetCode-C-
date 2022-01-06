/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<int> ns(n, 0), we(n, 0);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                we[i] = max(we[i], grid[i][j]);
                ns[i] = max(ns[i], grid[j][i]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                res += min(we[i], ns[j]) - grid[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

