/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
      int m=A.size(),n=A[0].size();
      vector<vector<int>> T(n,vector<int>(m,0));
      for(int i=0;i<m*n;++i){
          T[i%n][i/n] = A[i/n][i%n];
      }
      vector<int> s;
      return T;
    }
};
// @lc code=end

