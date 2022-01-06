/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<vector<int>, vector<string>> ht;
        for(auto str : strs){
            vector<int> cnt(26, 0);
            for(auto c : str){
                cnt[c-'a']++;
            }
            ht[cnt].emplace_back(str);
        }
        for(auto [_, v] : ht){
            res.emplace_back(v);
        }
        return res;
    }
};
// @lc code=end

