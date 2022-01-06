/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s; // 单调栈,此处存索引，不直接存值
        for(int i=0;i<n*2;i++){ // 拷贝原数组拼接在后面，模拟环
            int num = nums[i%n];
            while(!s.empty() && num>nums[s.top()]){
                res[s.top()] = num;
                s.pop();
            }
            s.emplace(i%n);
        }
        return res;
    }
};
// @lc code=end

