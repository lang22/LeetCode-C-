/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    int findPlace(vector<vector<int>> p, int k){
        int i = 0;
        for(;i<p.size() && k >= 0;++i){
            if(p[i].empty()) k--;
        }
        return i-1;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
        // 按照身高h升序，人数k降序排序
        sort(people.begin(), people.end(), 
            [] (vector<int> a, vector<int> b) -> bool {
                if(a[0] < b[0]) return true;
                else if(a[0] > b[0]) return false;
                else return a[1] > b[1];
            });
        // [[4,4],[5,2],[5,0],[6,1],[7,1],[7,0]]
        int n = people.size();
        vector<vector<int>> res(n);
        for(int i=0;i<n;++i){
            int k = people[i][1];
            int j = findPlace(res, k);
            res[j] = people[i];
        }
        return res;
        // res = 
        // [[],[],[],[],[4,4],[]]
        // [[],[],[5,2],[],[4,4],[]]
        // [[5,0],[],[5,2],[],[4,4],[]]
        // [[5,0],[],[5,2],[6,1],[4,4],[]]
        // [[5,0],[],[5,2],[6,1],[4,4],[7,1]]
        // [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
    }
};
// @lc code=end

