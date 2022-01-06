/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0, n = arr.size();
        unordered_map<int, int> latest; // 记录值val最近出现的位置
        vector<int> dp(n, 1); // 以值arr[i]结尾的最长定差子序列长度，最小为1
        for(int i = 0; i < n; ++ i){
            int preV = arr[i]-difference; // 要构成定差序列的前置值
            if(latest.find(preV) != latest.end()){ // 如果记录中存在该前置值
                dp[i] = dp[latest[preV]] + 1; // 把当前值接在最近的前置值后面，构成长度+1的新序列
            } // 不存在满足要求的前置值，则自身构成一个长度为1的序列（已默认初始化为1）
            latest[arr[i]] = i; // 更新当前值的最新出现位置
            res = max(res, dp[i]); // 更新当前最长定差子序列长度
        }
        return res;
    }
};
// @lc code=end

