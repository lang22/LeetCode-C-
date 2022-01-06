/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix.begin()->empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1; // 起点在右上角
        while(i < m && j >= 0){ // 搜索方向向下、向左
            int v = matrix[i][j];
            if(v == target){
                return true;
            }
            else if(v > target){
                j--; // 转向左，或者说排除这一列
            }
            else{
                i++; // 转向下，或者说排除这一行
            }
        }
        return false;
    }
};
// @lc code=end

