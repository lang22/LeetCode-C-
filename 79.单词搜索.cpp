/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
class Solution {
public:
    int ds[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool exist(vector<vector<char>>& board, string word) {
        function<bool(int, int, int)> dfs = [&](int i, int j, int k){
            if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != word[k]){
                return false;
            }
            if(k == word.length()-1){
                return true;
            }
            char tmp = board[i][j]; // 暂存当前位置的符号
            board[i][j] = ' '; // 将已访问过的当前位置置空，防止后续递归再次返回该位置
            bool res = false;
            for(auto d : ds){ // 递归遍历当前位置的四个相邻位置
                if(dfs(i+d[0], j+d[1], k+1)){
                    res = true;
                    break;
                }
            }
            board[i][j] = tmp; // 归位
            return res;
        };
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(dfs(i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

