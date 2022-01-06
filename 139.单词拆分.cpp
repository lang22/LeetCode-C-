/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    // 完全背包
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int maxlen = 0;
        unordered_set<string> st;
        vector<bool> dp(n+1, false); // dp[i]表示子串s[0,i)是否可以拆分成wordDic
        dp[0] = true; // 定义空字符串可以拆分
        for(int i=1;i<=n;++i){
            for(auto word : wordDict){
                int j = word.length();
                // 状态存在 && 状态可达 && 当前单词对应相同 
                if(i>=j && dp[i-j] && s.substr(i-j, j) == word){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n]; 
    }
};
// @lc code=end

