/*
 * @lc app=leetcode.cn id=1995 lang=cpp
 *
 * [1995] 统计特殊四元组
 */

// @lc code=start
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0, n = nums.size();
        int a, b, c, d;
        unordered_map<int,int> hash;
        for(c=2;c<n-1;++c){
            b = c - 1;
            for(a=0;a<b;++a){
                hash[nums[a]+nums[b]] ++;
            }
            for(d=b+2;d<n;++d){
                res += hash[nums[d]-nums[c]];
            }
        }
        return res;
    }
};
// @lc code=end

