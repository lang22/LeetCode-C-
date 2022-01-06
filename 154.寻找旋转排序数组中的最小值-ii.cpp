/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
// 将数组划分为左、右两部分
// 两个部分都是有序的子数组
// 左子数组的最小值（左边界）不小于右子数组的最大值（右边界）
// 要找到右子数组的左边界，它一定不大于左子数组中的元素
// 二分查找
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1, mid = 0;
        while(l < r){
            mid = (r + l) / 2;
            if(nums[mid] < nums[r]){ // 此时mid一定在右子数组中
                r = mid; // mid右边部分舍弃，mid可能是左边界
            }
            else if(nums[mid] > nums[r]){ // 此时mid一定在左子数组
                l = mid + 1; // mid左边包括自身都可以舍弃
            }
            else{ // 此时无法确定mid在哪个部分，但舍弃r没问题啊
                r--;
            }
        }
        // 最后l是右子数组的左边界，r是左子数组的右边界
        return nums[l];
    }
};
// @lc code=end

