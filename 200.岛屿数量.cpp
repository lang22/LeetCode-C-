/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int m, n;
    void inject(vector<vector<char>>& grid, int i, int j, char t){ // 感染函数
        if(grid[i][j] != '1') return ; // 当前不是感染源，无法感染
        grid[i][j] = t; // 标记已感染类群
        if(i > 0) inject(grid, i-1, j, t); // 尝试感染上方
        if(j < n-1) inject(grid, i, j+1, t); // 尝试感染右方
        if(i < m-1) inject(grid, i+1, j, t); // 尝试感染下方
        if(j > 0) inject(grid, i, j-1, t); // 尝试感染左方
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        char t = '2';
        m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                // 在逐个遍历的过程中，进行感染，记录感染类群
                if(grid[i][j] == '1'){
                    inject(grid, i, j, (char)(t+res));
                    res ++;
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return res;
    }
};
// @lc code=end

