/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#define SWAP(a, b) {int t = a; a = b; b = t;}
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 先上下交换
        for(int i=0;i<n/2;++i){
            for(int j=0;j<n;++j){
                SWAP(matrix[i][j], matrix[n-i-1][j]);
            }
        }
        // 再对角交换
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                SWAP(matrix[i][j], matrix[j][i]);
            }
        }
        return ;
    }
};
// @lc code=end

