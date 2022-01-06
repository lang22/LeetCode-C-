/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> nextG;
        vector<int> res(nums1.size(), -1);
        stack<int> s;
        // 单调栈法
        for(int i=0;i<nums2.size();i++){
            while(!s.empty() && nums2[i]>s.top()){
                nextG[s.top()] = nums2[i];
                s.pop();
            }
            s.emplace(nums2[i]);
        }
        while(!s.empty()){
          nextG[s.top()] = -1;
          s.pop();
        }
        for(int i=0;i<nums1.size();i++){
          res[i] = nextG[nums1[i]];
        }
        return res;
    }
};
// @lc code=end

